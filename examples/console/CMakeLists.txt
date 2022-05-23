PROJECT(SFML.Console)

SET(SFML_CONSOLE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(SFML_CONSOLE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(SFML.Console
        Source/Backend/SFML/SFML.cpp
        Source/Console.cpp)

#[[

The option /Za is used for support the keyword as 'not', 'and'
reference: The extended operator synonyms are keywords when /permissive-
or /Za (Disable language extensions) is specified. They aren't keywords
when Microsoft extensions are enabled.

Microsoft extensions are enabled by default. To ensure that your programs are fully portable,
you can disable Microsoft extensions by specifying the /permissive- or /Za (Disable language
extensions) option during compilation. These options disable some Microsoft-specific keywords.

Ref: https://docs.microsoft.com/en-us/cpp/cpp/keywords-cpp?view=msvc-170
#]]
SET_TARGET_PROPERTIES(SFML.Console PROPERTIES COMPILE_FLAGS /Za)
SET_TARGET_PROPERTIES(SFML.Console PROPERTIES CXX_STANDARD 17)
TARGET_INCLUDE_DIRECTORIES(SFML.Console PUBLIC $<BUILD_INTERFACE:${SFML_CONSOLE_SOURCE_DIR}/Include/>)

TARGET_LINK_LIBRARIES(SFML.Console PRIVATE SFML::Main SFML::System SFML::Window)

ADD_CUSTOM_COMMAND(TARGET SFML.Console POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SFML::Main> $<TARGET_FILE_DIR:SFML.Console>)


ADD_CUSTOM_COMMAND(TARGET SFML.Console POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SFML::System> $<TARGET_FILE_DIR:SFML.Console>)

ADD_CUSTOM_COMMAND(TARGET SFML.Console POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SFML::Window> $<TARGET_FILE_DIR:SFML.Console>)