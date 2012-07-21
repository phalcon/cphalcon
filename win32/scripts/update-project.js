var STDOUT = WScript.StdOut;
var STDERR = WScript.StdErr;
var WshShell = WScript.CreateObject("WScript.Shell");
var FSO = WScript.CreateObject("Scripting.FileSystemObject");
var SCRIPT_DIR=FSO.GetParentFolderName(WScript.ScriptFullName);
var WIN32_DIR=FSO.GetParentFolderName(SCRIPT_DIR);
var CPHALCON_PROJ = WIN32_DIR + '\\cphalcon.vcproj';
var PHALCON_DIR=FSO.GetParentFolderName(WIN32_DIR);
var PHALCON_DEV_SRC_DIR=PHALCON_DIR + '\\dev';
var PHALCON_RELEASE_SRC_DIR=PHALCON_DIR + '\\release';

var CWD = WshShell.CurrentDirectory;

function foreach(collection, callback) {
    for (var enumerator = new Enumerator(collection) ; !enumerator.atEnd(); enumerator.moveNext()) {
        callback(enumerator.item());
    }
}

function enumerateDirectory(depth, dirName, folderCallback, fileCallback) {
    var dir = FSO.GetFolder(dirName);
    if (dir) {
      foreach(dir.Files, function(file) {
          fileCallback(depth, file);
      });
      foreach(dir.SubFolders, function(subdir) {
          folderCallback(depth, subdir);
      });
    }
}

STDOUT.WriteLine();
STDOUT.WriteLine('Phalcon dev source dir: ' + PHALCON_DEV_SRC_DIR);
STDOUT.WriteLine('Phalcon release source dir: ' + PHALCON_RELEASE_SRC_DIR);
STDOUT.WriteLine('VS2008 project dir: ' + WIN32_DIR);
STDOUT.WriteLine('VS2008 project file: ' + CPHALCON_PROJ);

var projectFile = FSO.OpenTextFile(CPHALCON_PROJ);
var line, inFilesNode = false, 
    projectPrefix=[], projectSuffix=[];

while(!inFilesNode && !projectFile.AtEndOfStream) {
    line = projectFile.ReadLine();
    if (line.match(/<Files>/i)) {
        inFilesNode = true;
    }
    projectPrefix.push(line);
}

while(inFilesNode && !projectFile.AtEndOfStream) {
    line = projectFile.ReadLine();
    if (line.match(/<\/Files>/i)) {
        inFilesNode = false;
        projectSuffix.push(line);
    }
}

while(!projectFile.AtEndOfStream) {
    line = projectFile.ReadLine();
    projectSuffix.push(line);
}
projectFile.Close();

var filesSnippet = [],
    rootDir, 
    rootDirLen,
    relativeDir,
    onFolder = function(depth, dir) {
        var indent = Array(depth + 1).join('\t');
        filesSnippet.push(indent + '<Filter\r\n' + indent + '\tName="' + dir.Name + '"\r\n' + indent + '\t>');
        enumerateDirectory(depth + 1, dir.Path, onFolder, onFile);
        filesSnippet.push(indent + '</Filter>');
    },
    onFile = function(depth, file) {
        var indent = Array(depth + 1).join('\t'),
            relativePath = file.Path.substr(rootDirLen);
        
        if (file.Type == 'C Source' || file.Type == 'C/C++ Header') {
            filesSnippet.push(indent + '<File\r\n' + indent + '\tRelativePath="..\\' + relativeDir + '\\' + relativePath + '"\r\n' + indent + '\t>');
            objectFileOverride(depth + 1, file);
            filesSnippet.push(indent + '</File>');
        }
    },
    objectFileOverride = function(depth, file) {
        var indent = Array(depth + 1).join('\t'),
            configs = [ 'Debug TS|Win32', 'Release TS|Win32', 'Debug NTS|Win32', 'Release NTS|Win32'],
            relativePath = file.Path.substr(rootDirLen),
            i, len = configs.length,
            inReleaseDir = (relativeDir == 'release'),
            inReleaseConfig;
        
        relativePath = relativePath.substr(0, relativePath.lastIndexOf('\\'));

        for(i=0; i<len; ++i) {
            inReleaseConfig = (configs[i].substr(0, 7) == 'Release');
            if ((inReleaseDir != inReleaseConfig) || (relativePath.length > 0)) {
                filesSnippet.push(indent + '<FileConfiguration');
                filesSnippet.push(indent + '\tName="' + configs[i] + '"');
                if (inReleaseDir != inReleaseConfig) {
                    filesSnippet.push(indent + '\tExcludedFromBuild="true"');
                }
                filesSnippet.push(indent + '\t>');
                filesSnippet.push(indent + '\t<Tool\r\n' + indent + '\t\tName="VCCLCompilerTool"');
                if (relativePath.length > 0) {
                    filesSnippet.push(indent + '\t\tObjectFile="$(IntDir)\\' + relativePath + '\\"');
                }
                filesSnippet.push(indent + '\t/>');
                filesSnippet.push(indent + '</FileConfiguration>');
            }
        }
    };

rootDir = PHALCON_RELEASE_SRC_DIR;
rootDirLen = rootDir.length+1,
relativeDir = 'release';
filesSnippet.push('\t\t<Filter\r\n\t\t\tName="release"\r\n\t\t\t>');
enumerateDirectory(3, PHALCON_RELEASE_SRC_DIR, onFolder, onFile);
filesSnippet.push('\t\t</Filter>');
rootDir = PHALCON_DEV_SRC_DIR;
rootDirLen = rootDir.length+1,
relativeDir = 'dev';
filesSnippet.push('\t\t<Filter\r\n\t\t\tName="dev"\r\n\t\t\t>');
enumerateDirectory(3, PHALCON_DEV_SRC_DIR, onFolder, onFile);
filesSnippet.push('\t\t</Filter>');



filesSnippet = filesSnippet.join('\r\n');

var pad = function(number, length) {
        var str = '' + number;
        while (str.length < length) {
            str = '0' + str;
        }
        return str;
    },
    now = new Date(),
    nowStr = ('' + now.getFullYear() + '-' + pad(now.getMonth()+1,2) + '-' + pad(now.getDate(), 2) + 'T' + pad(now.getHours(), 2) + pad(now.getMinutes(), 2)),
    backupFilename = CPHALCON_PROJ + '.' + nowStr + '.backup';

FSO.CopyFile(CPHALCON_PROJ, backupFilename, true);

var newProjectFile = FSO.OpenTextFile(CPHALCON_PROJ, 2, true);

newProjectFile.WriteLine(projectPrefix.join('\r\n'));
newProjectFile.WriteLine(filesSnippet);
newProjectFile.WriteLine(projectSuffix.join('\r\n'));

newProjectFile.Close();
