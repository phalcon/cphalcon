<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Http/Request/File.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http\\Request',
    'file' => '/app/phalcon/Http/Request/File.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Http\\Request\\FileInterface',
        'file' => '/app/phalcon/Http/Request/File.zep',
        'line' => 13,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Request/File.zep',
    'line' => 37,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Http\\Request\\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *```php
 * use Phalcon\\Mvc\\Controller;
 *
 * class PostsController extends Controller
 * {
 *     public function uploadAction()
 *     {
 *         // Check if the user has uploaded files
 *         if ($this->request->hasFiles() == true) {
 *             // Print the real file names and their sizes
 *             foreach ($this->request->getUploadedFiles() as $file) {
 *                 echo $file->getName(), " ", $file->getSize(), "\\n";
 *             }
 *         }
 *     }
 * }
 *```
 *',
    'file' => '/app/phalcon/Http/Request/File.zep',
    'line' => 38,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'File',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'FileInterface',
        'file' => '/app/phalcon/Http/Request/File.zep',
        'line' => 39,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'error',
          'docblock' => '**
     * @var string|null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 43,
              'char' => 27,
            ),
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 47,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'extension',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 48,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 52,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'key',
          'docblock' => '**
     * @var string|null
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 53,
              'char' => 25,
            ),
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 55,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 57,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'realType',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 59,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'size',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 61,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'tmp',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 63,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'type',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 67,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'file',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 68,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 68,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 68,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 70,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'tempName',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 70,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'size',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 70,
                  'char' => 33,
                ),
                3 => 
                array (
                  'variable' => 'type',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 70,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'error',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 70,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 72,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 72,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 72,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 72,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 72,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 72,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'name',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 73,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 73,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 75,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'defined',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'PATHINFO_EXTENSION',
                          'file' => '/app/phalcon/Http/Request/File.zep',
                          'line' => 75,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 75,
                        'char' => 42,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 75,
                    'char' => 44,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'extension',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'pathinfo',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'name',
                                  'file' => '/app/phalcon/Http/Request/File.zep',
                                  'line' => 76,
                                  'char' => 52,
                                ),
                                'file' => '/app/phalcon/Http/Request/File.zep',
                                'line' => 76,
                                'char' => 52,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'constant',
                                  'value' => 'PATHINFO_EXTENSION',
                                  'file' => '/app/phalcon/Http/Request/File.zep',
                                  'line' => 76,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Http/Request/File.zep',
                                'line' => 76,
                                'char' => 72,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Request/File.zep',
                            'line' => 76,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Http/Request/File.zep',
                          'line' => 76,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 77,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 78,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 80,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'tempName',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 80,
                  'char' => 43,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 80,
                    'char' => 32,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'tmp_name',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 80,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 80,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 80,
                'char' => 43,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'tmp',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tempName',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 81,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 81,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 84,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'size',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 84,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 84,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'size',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 84,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 84,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 84,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'size',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'size',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 85,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 85,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 86,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 88,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'type',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 88,
                  'char' => 35,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 88,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'type',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 88,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 88,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 88,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'type',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'type',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 89,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 89,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 90,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 92,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'error',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 92,
                  'char' => 37,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'file',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 92,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'error',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 92,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 92,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 92,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'error',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'error',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 93,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 93,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 94,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 96,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'key',
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 96,
                'char' => 16,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'key',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 97,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 97,
                      'char' => 32,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 99,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Http\\Request\\File constructor
     *',
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 68,
          'last-line' => 103,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 106,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 106,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 106,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the real name of the uploaded file
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 105,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 105,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 104,
          'last-line' => 111,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRealType',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'finfo',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 114,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'mime',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 114,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 116,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'finfo',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'finfo_open',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'constant',
                          'value' => 'FILEINFO_MIME_TYPE',
                          'file' => '/app/phalcon/Http/Request/File.zep',
                          'line' => 116,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 116,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 116,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 116,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 118,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'finfo',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 118,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 118,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'resource',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 118,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 118,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 119,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 120,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 122,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mime',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'finfo_file',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'finfo',
                          'file' => '/app/phalcon/Http/Request/File.zep',
                          'line' => 122,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 122,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Http/Request/File.zep',
                            'line' => 122,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tmp',
                            'file' => '/app/phalcon/Http/Request/File.zep',
                            'line' => 122,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Http/Request/File.zep',
                          'line' => 122,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 122,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 122,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 122,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 124,
              'char' => 19,
            ),
            4 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'finfo_close',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'finfo',
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 124,
                      'char' => 26,
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 124,
                    'char' => 26,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 124,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 126,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'mime',
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 126,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 127,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets the real mime type of the upload file using finfo
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 113,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 113,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 112,
          'last-line' => 131,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSize',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 134,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'size',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 134,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 134,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the file size of the uploaded file
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 133,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 133,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 132,
          'last-line' => 139,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTempName',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'tmp',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 142,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 142,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the temporary name of the uploaded file
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 140,
          'last-line' => 148,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getType',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 151,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'type',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 151,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 151,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 152,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the mime type reported by the browser
     * This mime type is not completely secure, use getRealType() instead
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 150,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 150,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 149,
          'last-line' => 156,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUploadedFile',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'tmp',
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 159,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 161,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'tmp',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 161,
                      'char' => 24,
                    ),
                    'name' => 'getTempName',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 161,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 161,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 163,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'tmp',
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 163,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 163,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'string',
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 163,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 163,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_uploaded_file',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tmp',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 163,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 163,
                      'char' => 60,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Request/File.zep',
                  'line' => 163,
                  'char' => 61,
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 163,
                'char' => 61,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether the file has been uploaded via Post.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 158,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 158,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 157,
          'last-line' => 168,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'moveTo',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'destination',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 169,
              'char' => 47,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'move_uploaded_file',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 171,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tmp',
                        'file' => '/app/phalcon/Http/Request/File.zep',
                        'line' => 171,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 171,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 171,
                    'char' => 44,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'destination',
                      'file' => '/app/phalcon/Http/Request/File.zep',
                      'line' => 171,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Http/Request/File.zep',
                    'line' => 171,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 171,
                'char' => 58,
              ),
              'file' => '/app/phalcon/Http/Request/File.zep',
              'line' => 172,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Moves the temporary file to a destination within the application
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Http/Request/File.zep',
                'line' => 170,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Request/File.zep',
            'line' => 170,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Request/File.zep',
          'line' => 169,
          'last-line' => 173,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Http/Request/File.zep',
      'line' => 38,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Request/File.zep',
    'line' => 38,
    'char' => 5,
  ),
);