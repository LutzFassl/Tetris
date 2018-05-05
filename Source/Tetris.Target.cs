// Copyright Lutz Fassl

using UnrealBuildTool;
using System.Collections.Generic;

public class TetrisTarget : TargetRules
{
	public TetrisTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Tetris" } );
	}
}
