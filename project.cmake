add_executable(${ProjectName})
target_import_src(${ProjectName})

target_link_libraries(${ProjectName} PUBLIC -Wl,--start-group)
target_import_base(${ProjectName} PUBLIC)
target_import_cli11(${ProjectName} PUBLIC)
target_link_libraries(${ProjectName} PUBLIC -Wl,--end-group)
