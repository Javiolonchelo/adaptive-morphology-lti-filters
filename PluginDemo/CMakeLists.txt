# Javier Rodrigo López - javier.rlopez@alumnos.upm.es

cmake_minimum_required(VERSION 3.15)
project(
        PluginDemo
        VERSION 0.1.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# Fetch JUCE
include(FetchContent)
if (DEFINED ENV{JUCE_PATH} AND NOT "$ENV{JUCE_PATH}" STREQUAL "")
    FetchContent_Declare(JUCE SOURCE_DIR "$ENV{JUCE_PATH}")
else ()
    FetchContent_Declare(
            JUCE
            GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
            GIT_TAG 8.0.7)
endif ()
FetchContent_MakeAvailable(JUCE)

set(COMPANY_NAME "UPM")
set(PLUGIN_MANUFACTURER_CODE UPMa)

# Customize the plugin here
set(BUNDLE_ID com.UPM.PluginDemo)
set(PLUGIN_CODE PDem)
set(FORMATS AU VST3 Standalone)
set(PLUGIN_FINAL_NAME "Plugin Demo for Adaptive Morphology")

# Paths
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

# juce_set_aax_sdk_path(...)
juce_add_plugin(
        ${PROJECT_NAME}
        BUNDLE_ID
        com.UPM.PluginDemo
        COMPANY_NAME
        ${COMPANY_NAME}
        EDITOR_WANTS_KEYBOARD_FOCUS
        FALSE
        FORMATS
        ${FORMATS}
        IS_MIDI_EFFECT
        FALSE
        IS_SYNTH
        FALSE
        NEEDS_MIDI_INPUT
        FALSE
        NEEDS_MIDI_OUTPUT
        FALSE
        PLUGIN_CODE
        ${PLUGIN_CODE}
        PLUGIN_MANUFACTURER_CODE
        ${PLUGIN_MANUFACTURER_CODE}
        PRODUCT_NAME
        ${PLUGIN_FINAL_NAME}
        COPY_PLUGIN_AFTER_BUILD
        TRUE
        JUCE_ENABLE_MODULE_SOURCE_GROUPS
        TRUE
        ICON_BIG
        "${CMAKE_SOURCE_DIR}/assets/escudo.png"
        ICON_SMALL
        "${CMAKE_SOURCE_DIR}/assets/escudo.png"
        VST3_AUTO_MANIFEST
        TRUE)

juce_add_binary_data(
        BinaryData
        SOURCES
        # Images
        ${CMAKE_SOURCE_DIR}/assets/escudo.png
        # Fonts
        ${CMAKE_SOURCE_DIR}/assets/fonts/JuliaMono-ExtraBoldItalic.ttf)

target_sources(
        ${PROJECT_NAME}
        PRIVATE # .cpp
        ${SOURCE_PATH}/CustomLookAndFeel.cpp
        ${SOURCE_PATH}/PluginEditor.cpp
        ${SOURCE_PATH}/PluginProcessor.cpp
        ${SOURCE_PATH}/Knob.cpp
        ${SOURCE_PATH}/TitleBox.cpp
        ${SOURCE_PATH}/MyCanvas.cpp

        # .h
        ${SOURCE_PATH}/CustomLookAndFeel.h
        ${SOURCE_PATH}/PluginEditor.h
        ${SOURCE_PATH}/PluginProcessor.h
        ${SOURCE_PATH}/Knob.h
        ${SOURCE_PATH}/TitleBox.h
        ${SOURCE_PATH}/MyCanvas.h
        ${SOURCE_PATH}/FoundFilter.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_PATH})
message(STATUS "Source path: ${SOURCE_PATH}")

target_compile_definitions(
        ${PROJECT_NAME} PUBLIC DONT_SET_USING_JUCE_NAMESPACE JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0 JUCE_WEB_BROWSER=0)
target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE BinaryData juce::juce_audio_utils
        PUBLIC juce::juce_recommended_config_flags juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
