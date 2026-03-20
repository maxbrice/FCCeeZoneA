import unreal
import sys
import re
import os

def get_destination_folder_name_from_path(file_path):
    return file_path.split("/")[-2]

def get_package_name(asset_path):
    return asset_path.split(".")[0]

def get_name_from_path(file_path):
    return os.path.splitext(os.path.basename(file_path))[0]

def name_sanitizer(name):
    # sanitized_name = name.replace('-', '_')
    sanitized_name = name.replace(' ', '_')
    sanitized_name = sanitized_name.replace('.', '_')

    return sanitized_name

def get_files_with_extensions(folder_path, extensions):
    file_paths = []
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(extensions):
                file_paths.append(os.path.join(root, file))
    return file_paths

def import_scene(file_path, file_name, destination_folder_name, importer):
    file_name = name_sanitizer(file_name)
    destination_folder_name = name_sanitizer(destination_folder_name)

    # TODO assign the variable somewhere
    overwrite_folders = True

    # Create folder
    imported_assets_folder_local_path = f"/Game/Imports/{destination_folder_name}/{file_name}"
    content_directory = unreal.Paths.project_content_dir() + f"Imports/{destination_folder_name}/{file_name}"

    if unreal.Paths.directory_exists(content_directory):
        if overwrite_folders:
            unreal.EditorAssetLibrary.delete_directory(imported_assets_folder_local_path)
        else:
            return

    print(f'Creating folder at {imported_assets_folder_local_path}')
    unreal.EditorAssetLibrary.make_directory(imported_assets_folder_local_path)

    destination_folder = f'/Game/Imports/{destination_folder_name}'
    importer(file_name, file_path, destination_folder)


def datasmith_importer(file_name, file_path, destination_folder):
    #Probably not necessary, but it doesn't hurt
    destination_folder = name_sanitizer(destination_folder)

    #Level Directory
    level_directory = f'{destination_folder}/{file_name}/Level/{file_name}'

    # Create new level
    unreal.get_editor_subsystem(unreal.LevelEditorSubsystem).new_level(level_directory)

    # Create DataSmith scene
    datasmith_scene = unreal.DatasmithSceneElement.construct_datasmith_scene_from_file(file_path)

    # Settings datasmith base options
    base_options = datasmith_scene.get_options().base_options

    base_options.scene_handling = unreal.DatasmithImportScene.CURRENT_LEVEL
    base_options.static_mesh_options.generate_lightmap_u_vs = True
    base_options.include_material = True

    # Settings datasmith tessellation options (None in case of a 3Dxml file)
    '''
    tessellation_options = datasmith_scene.get_options(unreal.DatasmithCommonTessellationOptions)
    
    if tessellation_options:
        tessellation_options.options.chord_tolerance = chord_tolerance
        tessellation_options.options.max_edge_length = max_edge_length
        tessellation_options.options.normal_tolerance = normal_tolerance
        tessellation_options.options.stitching_technique = unreal.DatasmithCADStitchingTechnique.STITCHING_NONE
    '''

    # Import the scene into the current level
    result = datasmith_scene.import_scene(destination_folder)

    # Save imported static meshes and materials assets
    for static_mesh in result.imported_meshes:
        if static_mesh is not None:
            static_mesh_name = static_mesh.get_name()

            for i in range(static_mesh.get_num_sections(0)):
                material_interface = static_mesh.get_material(i)

                # Create new material instance name
                new_material_name = f"MI_{static_mesh_name}_{i}"

                # Get the path where the original material is stored
                original_material_path = material_interface.get_path_name()
                material_package_path = original_material_path.rsplit('/', 1)[0]

                # Create the new material instance path
                new_material_path = f"{material_package_path}/{new_material_name}"

                # Check if the material instance already exists
                existing_material = unreal.EditorAssetLibrary.find_asset_data(new_material_path)

                if not existing_material.is_valid():
                    # Duplicate the material instance
                    new_material = unreal.AssetToolsHelpers.get_asset_tools().duplicate_asset(
                        new_material_name,
                        material_package_path,
                        material_interface
                    )
                else:
                    # Load the existing material
                    new_material = unreal.EditorAssetLibrary.load_asset(new_material_path)

                # Assign the new material to the static mesh
                static_mesh.set_material(i, new_material)

                unreal.EditorAssetLibrary.save_loaded_asset(new_material)

                material_parent = material_interface.parent
                unreal.EditorAssetLibrary.save_loaded_asset(material_parent)
                unreal.EditorAssetLibrary.save_loaded_asset(static_mesh)

    # Save level
    unreal.get_editor_subsystem(unreal.LevelEditorSubsystem).save_all_dirty_levels()

def import_scene_from_file(path):
    file_path = path.replace('\\', '/')
    file_name = get_name_from_path(file_path)
    destination_folder_name = get_destination_folder_name_from_path(file_path)

    # print(f'file_path: {file_path}, file_name: {file_name}, destination_folder_name: {destination_folder_name}')
    import_scene(file_path, file_name, destination_folder_name, datasmith_importer)

def import_scene_from_folder(path):
    folder_path = path.replace('\\', '/')
    extensions = (".stp", ".3dxml")

    file_paths = get_files_with_extensions(folder_path, extensions)

    for file_path in file_paths:
        import_scene_from_file(file_path)
