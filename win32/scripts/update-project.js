var STDOUT = WScript.StdOut;
var STDERR = WScript.StdErr;
var WshShell = WScript.CreateObject("WScript.Shell");
var FSO = WScript.CreateObject("Scripting.FileSystemObject");
var SCRIPT_DIR=FSO.GetParentFolderName(WScript.ScriptFullName);
var WIN32_DIR=FSO.GetParentFolderName(SCRIPT_DIR);
var CPHALCON_PROJ = WIN32_DIR + '\\cphalcon.vcproj';
var PHALCON_DIR=FSO.GetParentFolderName(WIN32_DIR);
var PHALCON_SRC_DIR=PHALCON_DIR + '\\dev';

var CWD = WshShell.CurrentDirectory;

function foreach(collection, callback) {
    for (var enumerator = new Enumerator(collection) ; !enumerator.atEnd(); enumerator.moveNext()) {
        callback(enumerator.item());
    }
}

function enumerateDirectory(depth, dirName, folderCallback, fileCallback) {
    var dir = FSO.GetFolder(dirName);
    if (dir) {
        foreach(dir.SubFolders, function(subdir) {
            folderCallback(depth, subdir);
        });
        foreach(dir.Files, function(file) {
            fileCallback(depth, file);
        });
    }
}

STDOUT.WriteLine();
STDOUT.WriteLine('Phalcon source dir: ' + PHALCON_SRC_DIR);
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
    rootDir = PHALCON_SRC_DIR,
    rootDirLen = rootDir.length+1,
    onFolder = function(depth, dir) {
        var indent = Array(depth + 1).join('\t');
        filesSnippet.push(indent + '<Filter Name="' + dir.Name + '">');
        enumerateDirectory(depth + 1, dir.Path, onFolder, onFile);
        filesSnippet.push(indent + '</Filter>');
    },
    onFile = function(depth, file) {
        var indent = Array(depth + 1).join('\t'),
            relativePath = file.Path.substr(rootDirLen);
        
        if (file.Type == 'C Source' || file.Type == 'C/C++ Header') {
            filesSnippet.push(indent + '<File RelativePath="..\\dev\\' + relativePath + '">');
            objectFileOverride(depth + 1, file);
            filesSnippet.push(indent + '</File>');
        }
    },
    objectFileOverride = function(depth, file) {
        var indent = Array(depth + 1).join('\t'),
            configs = [ 'Debug TS|Win32', 'Release TS|Win32', 'Debug NTS|Win32', 'Release NTS|Win32'],
            relativePath = file.Path.substr(rootDirLen),
            i, len = configs.length;
        
        relativePath = relativePath.substr(0, relativePath.lastIndexOf('\\'));

        if (relativePath.length > 0) {
            for(i=0; i<len; ++i) {
                filesSnippet.push(indent + '<FileConfiguration Name="' + configs[i] + '">');
                filesSnippet.push(indent + '\t<Tool Name="VCCLCompilerTool" ObjectFile="$(IntDir)\\' + relativePath + '\\" />');
		        filesSnippet.push(indent + '</FileConfiguration>');
		    }
		}
    };

enumerateDirectory(2, PHALCON_SRC_DIR, onFolder, onFile);

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
