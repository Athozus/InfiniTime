#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"
#include <array>

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingChimesBehaviour : public Screen {
      public:
        SettingChimesBehaviour(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingChimesBehaviour() override;

        void UpdateSelected(lv_obj_t* object, lv_event_t event);

      private:
        struct Option {
          Controllers::Settings::ChimesBehaviourMode chimesBehaviourMode;
          const char* name;
        };
        static constexpr std::array<Option, 3> options = {{{Controllers::Settings::ChimesBehaviourMode::SingleVibe, "Single vibe"},
                                                           {Controllers::Settings::ChimesBehaviourMode::DoubleVibe, "Double vibe"},
                                                           {Controllers::Settings::ChimesBehaviourMode::LongVibe, "Long vibe"}}};

        std::array<lv_obj_t*, options.size()> cbOption;

        Controllers::Settings& settingsController;
      };
    }
  }
}
