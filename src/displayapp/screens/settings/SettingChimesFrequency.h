#pragma once

#include <cstdint>
#include <lvgl/lvgl.h>
#include "components/settings/Settings.h"
#include "displayapp/screens/Screen.h"
#include <array>

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingChimesFrequency : public Screen {
      public:
        SettingChimesFrequency(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingChimesFrequency() override;

        void UpdateSelected(lv_obj_t* object, lv_event_t event);

      private:
        struct Option {
          Controllers::Settings::ChimesFrequencyOption chimesFrequencyOption;
          const char* name;
        };
        static constexpr std::array<Option, 3> options = {{{Controllers::Settings::ChimesFrequencyOption::None, "Off"},
                                                           {Controllers::Settings::ChimesFrequencyOption::Hours, "Every hour"},
                                                           {Controllers::Settings::ChimesFrequencyOption::HalfHours, "Every 30 mins"}}};

        std::array<lv_obj_t*, options.size()> cbOption;

        Controllers::Settings& settingsController;
      };
    }
  }
}
