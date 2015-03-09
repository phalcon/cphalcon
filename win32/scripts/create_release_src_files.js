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
var input, output, inputLine, outputLine;
var fileList, pos, i, len, filename;
var state = 'COMMENT';
var skipComment = function(fileHandle) {
  while (!fileHandle.AtEndOfStream) {
    if (fileHandle.ReadLine().trim() === '*/') {
      fileHandle.ReadLine();
      return;
    }
  }
};
var copyFileContents = function(inputFilename, output) {
  var skipping = false, inputLine;
  var input = FSO.OpenTextFile(PHALCON_DEV_SRC_DIR + inputFilename, 1, true);

  skipComment(input);

  while(!input.AtEndOfStream) {
    inputLine = input.ReadLine();

    if (inputLine.substr(0,6) === 'extern') {
      inputLine = inputLine.substr(7);
    }
    if (inputLine.substr(0,8) === '#include') {
      continue;
    }
    if (skipping) {
      if ((inputLine.trim() !== '') && (inputLine.trim() !== '#endif')) {
        skipping = false;
      }
    } else if (inputLine.trim() === '#ifdef HAVE_CONFIG_H') {
      skipping = true;
    }
    if (!skipping) {
      output.WriteLine(inputLine);
    }
  }
  input.Close();
};

String.prototype.trim = function() {
    return this.replace(/(?:(?:^|\n)\s+|\s+(?:$|\n))/g,'').replace(/\s+/g,' ');
};

// copy php_phalcon.h
FSO.CopyFile(PHALCON_DEV_SRC_DIR + '\\php_phalcon.h', PHALCON_RELEASE_SRC_DIR + '\\php_phalcon.h', true);

// create phalcon.h
input = FSO.OpenTextFile(PHALCON_DEV_SRC_DIR + '\\phalcon.h', 1, true);
output = FSO.OpenTextFile(PHALCON_RELEASE_SRC_DIR + '\\phalcon.h', 2, true);

// copy header license
inputLine = input.ReadLine();
while(!input.AtEndOfStream && state === 'COMMENT') {
  
  if (inputLine.trim() == '*/') {
    state = 'SKIP';
  }
  output.WriteLine(inputLine);
  inputLine = input.ReadLine();
}

output.WriteLine();
output.WriteLine('#define PHALCON_RELEASE 1');
output.WriteLine();

while(!input.AtEndOfStream && state === 'SKIP') {
  inputLine = input.ReadLine();
  if (inputLine.trim() !== '') {
    state = 'FORWARD_DECLARES';
  }
}

while(!input.AtEndOfStream && state === 'FORWARD_DECLARES') {
  if (inputLine.trim().substr(0, 6) !== 'extern') {
    state = 'PHP_METHODS';
  }
  if ((inputLine.indexOf('_test_') < 0) && (inputLine.indexOf('_internal_') < 0)) {
    outputLine = inputLine.substr(7);
    output.WriteLine(outputLine);
  }
  inputLine = input.ReadLine();
}

while(!input.AtEndOfStream && (state === 'PHP_METHODS' || state === 'SKIP')) {
  if ((inputLine.indexOf('_Test,') > 0) || (inputLine.indexOf('_Internal_') > 0)) {
    state = 'SKIP';
  }

  if (state === 'SKIP') {
    if (inputLine.trim() === '') {
      state = 'PHP_METHODS';
    }
  } else {
    outputLine = inputLine;
    output.WriteLine(outputLine);
  }

  inputLine = input.ReadLine();

  if (inputLine.trim() !== '' && inputLine.substr(0,10) !== 'PHP_METHOD') {
    state = 'METHOD_ARGUMENTS';
  }
}

while(!input.AtEndOfStream && (state === 'METHOD_ARGUMENTS' || state === 'SKIP')) {
  if ((inputLine.indexOf('_test_') > 0) || (inputLine.indexOf('_internal_') > 0)) {
    state = 'SKIP';
  }

  if (state === 'SKIP') {
    if (inputLine.trim() === '') {
      state = 'METHOD_ARGUMENTS';
    }
  } else {
    outputLine = inputLine;
    output.WriteLine(outputLine);
  }

  inputLine = input.ReadLine();
  
  if (inputLine.substr(0,18) === 'PHALCON_INIT_FUNCS') {
    state = 'PHALCON_INIT_FUNCS';
  }
}

while(!input.AtEndOfStream) {
  if ((inputLine.indexOf('_test_') > 0) || (inputLine.indexOf('_internal_') > 0)) {
    state = 'SKIP';
  }

  if (state === 'SKIP') {
    if (inputLine.trim() === '') {
      state = 'PHALCON_INIT_FUNCS';
    }
  } else {
    outputLine = inputLine;
    output.WriteLine(outputLine);
  }

  inputLine = input.ReadLine();
}

output.WriteLine();

output.Close();
input.Close();

// create phalcon.c
output = FSO.OpenTextFile(PHALCON_RELEASE_SRC_DIR + '\\phalcon.c', 2, true);

state = 'COMMENT';
input = FSO.OpenTextFile(PHALCON_DEV_SRC_DIR + '\\kernel\\main.h', 1, true);

// copy header license
inputLine = input.ReadLine();
while(!input.AtEndOfStream && state === 'COMMENT') {
  
  if (inputLine.trim() == '*/') {
    state = 'SKIP';
  }
  output.WriteLine(inputLine);
  inputLine = input.ReadLine();
}

output.WriteLine();
output.WriteLine();
output.WriteLine('#ifdef HAVE_CONFIG_H');
output.WriteLine('#include "config.h"');
output.WriteLine('#endif');
output.WriteLine();
output.WriteLine('#include "php.h"');
output.WriteLine('#include "php_phalcon.h"');
output.WriteLine('#include "phalcon.h"');
output.WriteLine();
output.WriteLine('#include "main/php_main.h"');
output.WriteLine('#include "ext/standard/php_string.h"');
output.WriteLine();
output.WriteLine('#include "Zend/zend_API.h"');
output.WriteLine('#include "Zend/zend_operators.h"');
output.WriteLine('#include "Zend/zend_exceptions.h"');
output.WriteLine('#include "Zend/zend_interfaces.h"');
output.WriteLine('#include "Zend/zend_execute.h"');
output.WriteLine();

while(!input.AtEndOfStream) {
  if ((inputLine.substr(0,6) === 'extern') && (inputLine.indexOf('phalcon') > 0)) {
      inputLine = inputLine.substr(7);
  }
  output.WriteLine(inputLine);
  
  inputLine = input.ReadLine();
}
input.Close();

output.WriteLine();
copyFileContents('\\kernel\\fcall.h', output);
copyFileContents('\\kernel\\require.h', output);
copyFileContents('\\kernel\\debug.h', output);
copyFileContents('\\kernel\\assert.h', output);
copyFileContents('\\kernel\\object.h', output);
copyFileContents('\\kernel\\array.h', output);
copyFileContents('\\kernel\\operators.h', output);
copyFileContents('\\kernel\\concat.h', output);
copyFileContents('\\kernel\\memory.h', output);
output.WriteLine();

input = FSO.OpenTextFile(PHALCON_DEV_SRC_DIR + '\\config.m4', 1, true);
while (!input.AtEndOfStream) {
  inputLine = input.ReadLine();
  if (inputLine.indexOf('PHP_NEW_EXTENSION') >= 0) {
    fileList = inputLine;
    break;
  }
}
input.Close();

pos = fileList.indexOf(', ');
fileList = fileList.substr(pos+2);
pos = fileList.indexOf(', ');
fileList = fileList.substr(0, pos);

fileList = fileList.split(' ');
len = fileList.length;
for (i=0; i<len; ++i) {
  if (fileList[i] !== 'phalcon.c') {
    filename = '\\' + fileList[i].replace(/\//g, '\\');
    if ((filename.indexOf('\\internal\\') < 0) && (filename.indexOf('test.c') < 0)) {
      copyFileContents(filename, output);
    }
  }
}

input = FSO.OpenTextFile(PHALCON_DEV_SRC_DIR + '\\phalcon.c', 1, true);
while (!input.AtEndOfStream) {
  inputLine = input.ReadLine();
  if (inputLine.trim().substr(0, 27) === 'ZEND_DECLARE_MODULE_GLOBALS') {
    output.WriteLine(inputLine);
    break;
  }
}

var skippedLastLine = false;
while (!input.AtEndOfStream) {
  inputLine = input.ReadLine();
  if (skippedLastLine && inputLine.trim() === '') {
    continue;
  }
  if ((inputLine.indexOf('_test;') > 0) || (inputLine.indexOf('_internal_test') > 0)
   || (inputLine.indexOf('_test_') > 0)) {
    skippedLastLine = true;
    continue;
  }
  skippedLastLine = false;
  output.WriteLine(inputLine);
  
  if (inputLine.trim().substr(0, 24) === 'ZEND_INIT_MODULE_GLOBALS') {
    break;
  }

}

state = 'NOT_SKIP';
inputLine = input.ReadLine();
while(!input.AtEndOfStream) {
  if ((inputLine.indexOf('_test_') > 0) || (inputLine.indexOf('_internal_test') > 0)) {
    state = 'SKIP';
  }

  if (state === 'SKIP') {
    if (inputLine.trim() === '') {
      state = 'NOT_SKIP';
    }
  } else {
    outputLine = inputLine;
    output.WriteLine(outputLine);
  }

  inputLine = input.ReadLine();
}

output.WriteLine();


input.Close();
output.Close();
