<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Session\\Adapter',
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Helper\\Str',
        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
        'line' => 13,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Session\\Exception',
        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
        'line' => 14,
        'char' => 30,
      ),
    ),
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
    'line' => 35,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Session\\Adapter\\Stream
 *
 * This is the file based adapter. It stores sessions in a file based system
 *
 * ```php
 * <?php
 *
 * use Phalcon\\Session\\Manager;
 * use Phalcon\\Session\\Adapter\\Stream;
 *
 * $session = new Manager();
 * $files = new Stream(
 *     [
 *         \'savePath\' => \'/tmp\',
 *     ]
 * );
 * $session->setHandler($files);
 * ```
 *',
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
    'line' => 36,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'Noop',
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'path',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 41,
            'char' => 20,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 43,
          'char' => 10,
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
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 43,
                'char' => 52,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 43,
              'char' => 52,
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
                  'variable' => 'path',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 45,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'options',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 45,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 47,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'scall',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 0,
                'class' => 'parent',
                'dynamic' => 0,
                'name' => '__construct',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 47,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 47,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 47,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 49,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'options',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 49,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 49,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 49,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 49,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 55,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fetch',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 55,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 55,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'savePath',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 55,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 55,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 55,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 55,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'path',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'ini_get',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'session.save_path',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 56,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 56,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 56,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 56,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 57,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 59,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_writable',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 59,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 59,
                        'char' => 38,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 59,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 59,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 59,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'concat',
                          'left' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'string',
                              'value' => 'The save_path [',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 60,
                              'char' => 49,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'path',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 60,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 60,
                            'char' => 56,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => ']is not writeable',
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 60,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 60,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 60,
                        'char' => 75,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 60,
                    'char' => 76,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 61,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 63,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'scall',
                    'dynamic-class' => 0,
                    'class' => 'Str',
                    'dynamic' => 0,
                    'name' => 'dirSeparator',
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 63,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 63,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 63,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 63,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 64,
              'char' => 5,
            ),
          ),
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 44,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 43,
          'last-line' => 66,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'destroy',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 66,
              'char' => 35,
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
                  'variable' => 'file',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 68,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 70,
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
                  'variable' => 'file',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 70,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 70,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 70,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 70,
                        'char' => 38,
                      ),
                      'name' => 'getPrefixedName',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 70,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 70,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 70,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 70,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 70,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 72,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'file_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 72,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 72,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 72,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_file',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'file',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 72,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 72,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 72,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 72,
                'char' => 47,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'fcall',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'unlink',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'file',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 73,
                          'char' => 24,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 73,
                        'char' => 24,
                      ),
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 73,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 74,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 76,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 76,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 77,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 67,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 67,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 66,
          'last-line' => 79,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'gc',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'maxlifetime',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 79,
              'char' => 39,
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
                  'variable' => 'file',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 81,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'pattern',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 81,
                  'char' => 26,
                ),
                2 => 
                array (
                  'variable' => 'time',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 81,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 83,
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
                  'variable' => 'pattern',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 83,
                          'char' => 28,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'path',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 83,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 83,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 83,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'prefix',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 83,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 83,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 83,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => '*',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 83,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 83,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 83,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'time',
                  'expr' => 
                  array (
                    'type' => 'sub',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'time',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 84,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'maxlifetime',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 84,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 84,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 84,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 86,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'glob',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'pattern',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 86,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 86,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 86,
                'char' => 35,
              ),
              'value' => 'file',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'file_exists',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 87,
                              'char' => 32,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 87,
                            'char' => 32,
                          ),
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 87,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_file',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 88,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 88,
                            'char' => 28,
                          ),
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 88,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 88,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'less',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'filemtime',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'file',
                                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                                'line' => 89,
                                'char' => 31,
                              ),
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 89,
                              'char' => 31,
                            ),
                          ),
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 89,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'time',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 89,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 89,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 89,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 89,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'unlink',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'file',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 90,
                              'char' => 28,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 90,
                            'char' => 28,
                          ),
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 90,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 91,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 94,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 94,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 80,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 80,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 79,
          'last-line' => 97,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'open',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'savePath',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 97,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sessionName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 97,
              'char' => 55,
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
                  'variable' => 'path',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 99,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 101,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 101,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'ends_with',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'savePath',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 101,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 101,
                      'char' => 39,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => '/',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 101,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 101,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 101,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 101,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'path',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'savePath',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 102,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => '/',
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 102,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 102,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 102,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 103,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 105,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 105,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 105,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 107,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 107,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 108,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 98,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 98,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 97,
          'last-line' => 110,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'read',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 110,
              'char' => 32,
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
                  'variable' => 'data',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 112,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 112,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 114,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 114,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 114,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 114,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 114,
                        'char' => 38,
                      ),
                      'name' => 'getPrefixedName',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 114,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 114,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 114,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 114,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 114,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'data',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 115,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 115,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 117,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'file_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 117,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 117,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 117,
                'char' => 30,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'data',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'file_get_contents',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                              'line' => 118,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 118,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 118,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 118,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 120,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'bool',
                      'value' => 'false',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 120,
                      'char' => 24,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'data',
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 120,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 120,
                    'char' => 31,
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
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 121,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 122,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 123,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 125,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'data',
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 125,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 110,
          'last-line' => 128,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'write',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'id',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 128,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 128,
              'char' => 43,
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
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 130,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 132,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 132,
                        'char' => 25,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 132,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 132,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 132,
                        'char' => 38,
                      ),
                      'name' => 'getPrefixedName',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'id',
                            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                            'line' => 132,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                          'line' => 132,
                          'char' => 57,
                        ),
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 132,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                    'line' => 132,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 132,
                  'char' => 58,
                ),
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 134,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 134,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'fcall',
                  'name' => 'file_put_contents',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 134,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 134,
                      'char' => 48,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'data',
                        'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                        'line' => 134,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                      'line' => 134,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                  'line' => 134,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 134,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Session/Adapter/Stream.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
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
                'file' => '/app/phalcon/Session/Adapter/Stream.zep',
                'line' => 129,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Session/Adapter/Stream.zep',
            'line' => 129,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Session/Adapter/Stream.zep',
          'line' => 128,
          'last-line' => 136,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Session/Adapter/Stream.zep',
      'line' => 36,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Session/Adapter/Stream.zep',
    'line' => 36,
    'char' => 5,
  ),
);