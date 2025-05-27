# DiceSystemDemo

# 🎲 Dice System Plugin – Demo Project for Unreal Engine 5

A modular, extensible dice system written in **C++ and Blueprint** for Unreal Engine 5.  
This system supports dice rolling, outcome resolution, and drag-and-drop UI, designed for turn-based interaction systems.

## 🔧 What This Project Includes

- A reusable C++ plugin: `DiceSystem/`
- A complete demo project: `DiceSystemDemo/`
- UI with drag-and-drop dice slotting
- Data-driven outcome resolution (Fail, Normal, Strong)
- Player-to-target interaction with a dice overlay (no combat or AI logic)


## 💡 How to Use in Your Game

1. Add the `DiceSystem` plugin to your project.
2. Attach `UDiceRollComponent` to your `PlayerState` (or any actor class).
3. Add `WBP_DiceOverlay` to your HUD and bind it to a `DiceWidgetController`.
4. Call `RollDice()` from your game logic.
5. Resolve results using `ULuluDiceResolutionLibrary`.


## 📝 Notes

- No Gameplay Ability System (GAS) used — plugin is intentionally simple and focused.
- Enemy actor is included for interaction demo only — no AI or combat.
- Dice UI system is fully contained and customizable.


## 📄 License

This project is shared for **portfolio and educational** purposes only.  
Please contact me if you’d like to use it commercially.


## 👩‍💻 Author

**Arzu Mert**  
Game Developer  
🔗 [Portfolio Website](https://mertarzu.github.io)

