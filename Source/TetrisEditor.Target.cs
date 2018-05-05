// Copyright Lutz Fassl

using UnrealBuildTool;
using System.Collections.Generic;

public class TetrisEditorTarget : TargetRules
{
	public TetrisEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Tetris" } );
	}
}
