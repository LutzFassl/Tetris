<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1525536446620" ID="ID_1322909878" MODIFIED="1525545212128" TEXT="Tetris">
<node CREATED="1525536457135" ID="ID_1095477051" MODIFIED="1525536762480" POSITION="right" TEXT="Spielfeld">
<node CREATED="1525536459177" ID="ID_1029418590" MODIFIED="1525536465193" TEXT="Breit 10"/>
<node CREATED="1525536465717" ID="ID_1817570820" MODIFIED="1525536622241" TEXT="Hoch 20"/>
</node>
<node CREATED="1525537322611" ID="ID_1525599735" MODIFIED="1525537323955" POSITION="right" TEXT="Inputs">
<node CREATED="1525537324602" ID="ID_1688329950" MODIFIED="1525537329832" TEXT="Space: MoveDown"/>
<node CREATED="1525537331290" ID="ID_1068429440" MODIFIED="1525537335532" TEXT="Left/Right Arrow">
<node CREATED="1525537336262" ID="ID_617753351" MODIFIED="1525537342773" TEXT="Move tetromino"/>
</node>
<node CREATED="1525537344962" ID="ID_1407862697" MODIFIED="1525537350791" TEXT="Up key">
<node CREATED="1525537350791" ID="ID_1878271767" MODIFIED="1525537356440" TEXT="Turn tetromino"/>
</node>
<node CREATED="1525537357722" ID="ID_1675101215" MODIFIED="1525537365361" TEXT="Down Key">
<node CREATED="1525537365362" ID="ID_1763524660" MODIFIED="1525537369087" TEXT="Move down"/>
</node>
</node>
<node CREATED="1525537250592" ID="ID_972346368" MODIFIED="1525537251607" POSITION="right" TEXT="Tasks">
<node CREATED="1525537254394" ID="ID_420689672" MODIFIED="1525537257208" TEXT="Tetromino">
<node CREATED="1525537266068" ID="ID_1579829749" MODIFIED="1525539257064" TEXT="Descent at &quot;Interval&quot; rate">
<node CREATED="1525537279570" ID="ID_458284508" MODIFIED="1525539262104" TEXT="Interval = 1/s etc. depending on difficulty">
<node CREATED="1525537292487" ID="ID_1919610077" MODIFIED="1525539275222" TEXT="Interval will shorten during playing">
<node CREATED="1525537310407" ID="ID_1648480551" MODIFIED="1525537314935" TEXT="based on player success"/>
</node>
</node>
</node>
</node>
<node CREATED="1525537257881" ID="ID_680579461" MODIFIED="1525537260769" TEXT="GameManager">
<node CREATED="1525537544187" ID="ID_1185558450" MODIFIED="1525537545391" TEXT="Cycle">
<node CREATED="1525537381130" ID="ID_1854351965" MODIFIED="1525537417527" TEXT="Show (spawn?) next tetromino in side view (random)"/>
<node CREATED="1525537412459" ID="ID_639545039" MODIFIED="1525537423016" TEXT="Spawn actual tetromino"/>
<node CREATED="1525537423301" ID="ID_1437623014" MODIFIED="1525537492677" TEXT="Make PlayerController possessed the Tetromino"/>
<node CREATED="1525537519270" ID="ID_889306479" MODIFIED="1525537535412" TEXT="When finished, depossess tetromino"/>
</node>
<node CREATED="1525537550394" ID="ID_1332043140" MODIFIED="1525539251070" TEXT="At every &quot;Interval&quot;">
<node CREATED="1525537501807" ID="ID_1418287177" MODIFIED="1525537510644" TEXT="Move Tetromino down">
<icon BUILTIN="help"/>
<node CREATED="1525537511698" ID="ID_404839197" MODIFIED="1525537518546" TEXT="or Tetromino class responsible?"/>
</node>
<node CREATED="1525538233520" ID="ID_167210643" MODIFIED="1525538249543" TEXT="Check for full rows --&gt; Delete"/>
</node>
</node>
</node>
<node CREATED="1525536697335" ID="ID_648664092" MODIFIED="1525536703203" POSITION="right" TEXT="Class structure">
<node CREATED="1525536711569" ID="ID_1858377469" MODIFIED="1525536765873" TEXT="Game Manager">
<node CREATED="1525537233965" ID="ID_1708997517" MODIFIED="1525548385382" TEXT="SceneComponent">
<node CREATED="1525537236125" ID="ID_511267490" MODIFIED="1525537240536" TEXT="GameManager C++">
<node CREATED="1525537241506" ID="ID_1133744071" MODIFIED="1525537245696" TEXT="GameManager BP"/>
</node>
</node>
<node CREATED="1525548367406" FOLDED="true" ID="ID_1032516052" MODIFIED="1525548376726" TEXT="Decision for Base Class">
<node CREATED="1525538573875" ID="ID_597346269" MODIFIED="1525538837466" TEXT="SceneComponent? = Dummy Component">
<icon BUILTIN="button_ok"/>
</node>
<node CREATED="1525538593896" ID="ID_283916655" MODIFIED="1525538595844" TEXT="Game Mode?">
<node CREATED="1525538749099" ID="ID_892494492" MODIFIED="1525538788346" TEXT="No, Game mode is constant for a game. What if u want to load new game? It has to be a component inferior to Game Mode">
<arrowlink DESTINATION="ID_225200234" ENDARROW="Default" ENDINCLINATION="508;0;" ID="Arrow_ID_806458633" STARTARROW="None" STARTINCLINATION="508;0;"/>
<icon BUILTIN="closed"/>
</node>
</node>
<node CREATED="1525538689029" ID="ID_225200234" MODIFIED="1525538788346" TEXT="Game Moode -&gt; SceneComponent?">
<linktarget COLOR="#b0b0b0" DESTINATION="ID_225200234" ENDARROW="Default" ENDINCLINATION="508;0;" ID="Arrow_ID_806458633" SOURCE="ID_892494492" STARTARROW="None" STARTINCLINATION="508;0;"/>
<icon BUILTIN="closed"/>
<node CREATED="1525538791275" ID="ID_725786275" MODIFIED="1525538797772" TEXT="same reason why not"/>
</node>
</node>
</node>
<node CREATED="1525536716020" ID="ID_1336956925" MODIFIED="1525536719143" TEXT="Tetromino:">
<node CREATED="1525536721831" ID="ID_527910044" MODIFIED="1525536722978" TEXT="APawn">
<node CREATED="1525536733792" ID="ID_1093714405" MODIFIED="1525536741933" TEXT="Tetromino C++">
<node CREATED="1525536742495" ID="ID_952748015" MODIFIED="1525536747921" TEXT="Tetromino BP">
<node CREATED="1525536790056" ID="ID_129934044" MODIFIED="1525536857214" TEXT="4x UStaticMeshes W&#xfc;rfel"/>
<node CREATED="1525536846382" ID="ID_209726439" MODIFIED="1525536867394" TEXT="n&#xf6;tig, dass UstaticMesh der W&#xfc;rfel BP oder C++ hat??">
<node CREATED="1525537076634" ID="ID_1648516499" MODIFIED="1525537081523" TEXT="eventuell -&gt; sp&#xe4;ter hinzuf&#xfc;gen"/>
</node>
</node>
</node>
</node>
<node CREATED="1525537123209" ID="ID_862851199" MODIFIED="1525537144170" TEXT="wird possessed von PlayerController"/>
<node CREATED="1525538382631" ID="ID_681991229" MODIFIED="1525538385605" TEXT="kann Inputs verarbeiten"/>
</node>
<node CREATED="1525538946830" ID="ID_265806901" MODIFIED="1525538954379" TEXT="Tetromino Subclasses">
<node CREATED="1525538993876" ID="ID_972832075" MODIFIED="1525538995979" TEXT="Symmetric">
<node CREATED="1525538954380" ID="ID_458259257" MODIFIED="1525538958091" TEXT="straight"/>
<node CREATED="1525538960988" ID="ID_411302108" MODIFIED="1525538964314" TEXT="square"/>
<node CREATED="1525538966706" ID="ID_1119245345" MODIFIED="1525538968274" TEXT="T"/>
</node>
<node CREATED="1525539000389" ID="ID_1709243075" MODIFIED="1525539005169" TEXT="Assymetric">
<node CREATED="1525538974139" ID="ID_1618477853" MODIFIED="1525539009847" TEXT="chirality_L"/>
<node CREATED="1525538974139" ID="ID_543468093" MODIFIED="1525539015226" TEXT="chirality_R"/>
<node CREATED="1525539021885" ID="ID_314957402" MODIFIED="1525539025576" TEXT="skew_L"/>
<node CREATED="1525539025846" ID="ID_873623181" MODIFIED="1525539027247" TEXT="skew_R"/>
</node>
</node>
<node CREATED="1525537440746" ID="ID_93741977" MODIFIED="1525537447095" TEXT="PlayerController:">
<node CREATED="1525537448834" ID="ID_1691967604" MODIFIED="1525537452217" TEXT="APlayerController">
<node CREATED="1525537472406" ID="ID_1530393421" MODIFIED="1525537476287" TEXT="PlayerController C++">
<node CREATED="1525537479745" ID="ID_1169545775" MODIFIED="1525537482430" TEXT="PlayerController BP"/>
</node>
</node>
</node>
</node>
<node CREATED="1525537656977" ID="ID_777772739" MODIFIED="1525537659170" POSITION="right" TEXT="Features">
<node CREATED="1525537659953" ID="ID_1175708832" MODIFIED="1525537662633" TEXT="GameManager">
<node CREATED="1525537663186" ID="ID_1621443124" MODIFIED="1525539312889" TEXT="TriggerVolume as default subobject, one for each row"/>
</node>
</node>
<node CREATED="1525539351274" ID="ID_63529184" MODIFIED="1525539353155" POSITION="right" TEXT="Appearance">
<node CREATED="1525538043403" ID="ID_87902187" MODIFIED="1525538046481" TEXT="3d Models">
<node CREATED="1525538046483" ID="ID_1929384246" MODIFIED="1525538047640" TEXT="Cube">
<node CREATED="1525538048200" ID="ID_1600029289" MODIFIED="1525538056884" TEXT="Shape_Cube, Static Mesh, StarterContent"/>
<node CREATED="1525538069201" ID="ID_1993790573" MODIFIED="1525538082910" TEXT="Metal Material: Burnished, Different colors"/>
</node>
</node>
<node CREATED="1525539357090" ID="ID_1123758045" MODIFIED="1525539358012" TEXT="Colors">
<node CREATED="1525541322925" ID="ID_1981286816" MODIFIED="1525541326794" TEXT="Microsoft Tetris"/>
</node>
</node>
<node CREATED="1525539227498" ID="ID_739895697" MODIFIED="1525539230067" POSITION="right" TEXT="TODO"/>
<node CREATED="1525545218488" ID="ID_1477333266" MODIFIED="1525545220262" POSITION="right" TEXT="Notes"/>
</node>
</map>
