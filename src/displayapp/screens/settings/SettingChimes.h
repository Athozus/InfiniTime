#pragma once

#include <array>
#include <memory>
#include "displayapp/screens/Screen.h"
#include "displayapp/screens/ScreenList.h"
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/List.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class SettingChimes : public Screen {
      public:
        SettingChimes(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~SettingChimes() override;

        bool OnTouchEvent(Pinetime::Applications::TouchEvents event) override;

      private:
        auto CreateScreenList() const;
        std::unique_ptr<Screen> CreateScreen(unsigned int screenNum) const;

        Controllers::Settings& settingsController;

        static constexpr int entriesPerScreen = 4;

        // Increment this when more space is needed
        static constexpr int nScreens = 1;

        static constexpr std::array<List::Applications, entriesPerScreen * nScreens> entries {{
          {Symbols::clock, "Frequency", Apps::SettingChimesFrequency},
          {Symbols::clock, "Behaviour", Apps::SettingChimesBehaviour},
          {Symbols::none, "None", Apps::None},
          {Symbols::none, "None", Apps::None},
        }};
        ScreenList<nScreens> screens;
      };
    }
  }
}
