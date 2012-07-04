project(activitymanager-plugin-activityranking)

include_directories(
   ${CMAKE_SOURCE_DIR}/src
   ${CMAKE_BINARY_DIR}/src
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}/../..
   ${CMAKE_CURRENT_BINARY_DIR}
   ${KDE4_INCLUDES}
   )

set(
   activityranking_SRCS
   activityranking.cpp
   activityrankingplugin.cpp
   ActivityData.cpp
   Location.cpp
   ../../Plugin.cpp
   )

qt4_add_dbus_adaptor(
   activityranking_SRCS org.kde.ActivityManager.ActivityRanking.xml
   activityranking.h ActivityRanking
   )

qt4_add_dbus_interface(
   activityranking_SRCS org.kde.LocationManager.xml
   LocationManagerInterface
   )

kde4_add_plugin(
   activitymanager_plugin_activityranking
   ${activityranking_SRCS}
   )

target_link_libraries(
   activitymanager_plugin_activityranking
   ${QT_QTSQL_LIBRARIES}
   ${KDE4_KDECORE_LIBS}
   ${KDE4_KDEUI_LIBS}
   )

install(TARGETS activitymanager_plugin_activityranking DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES activitymanager-plugin-activityranking.desktop DESTINATION ${SERVICES_INSTALL_DIR})
