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
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Adapter',
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Logger\\Adapter',
        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
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
        'name' => 'Phalcon\\Logger\\Exception',
        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
        'line' => 14,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Logger\\Formatter\\FormatterInterface',
        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
        'line' => 15,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
        'line' => 16,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'UnexpectedValueException',
        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
        'line' => 17,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 33,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Adapter\\Stream
 *
 * Adapter to store logs in plain text files
 *
 *```php
 * $logger = new \\Phalcon\\Logger\\Adapter\\Stream("app/logs/test.log");
 *
 * $logger->log("This is a message");
 * $logger->log(\\Phalcon\\Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *
 * $logger->close();
 *```
 *',
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 34,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Stream',
    'abstract' => 0,
    'final' => 0,
    'extends' => 'AbstractAdapter',
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
          'name' => 'handler',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
            'line' => 41,
            'char' => 29,
          ),
          'docblock' => '**
     * Stream handler resource
     *
     * @var resource|null
     *',
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
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
          'name' => 'mode',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'ab',
            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
            'line' => 48,
            'char' => 24,
          ),
          'docblock' => '**
     * The file open mode. Defaults to "ab"
     *
     * @var string
     *',
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 54,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'docblock' => '**
     * Stream name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 55,
              'char' => 26,
            ),
          ),
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 61,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'options',
          'docblock' => '**
     * Path options
     *
     * @var array
     *',
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 66,
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
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 67,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'options',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 67,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 67,
              'char' => 65,
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
                  'variable' => 'mode',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 69,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 74,
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
                  'value' => 'mode',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 74,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 74,
                    'char' => 31,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 74,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 74,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 74,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'memstr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mode',
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 75,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 75,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'r',
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 75,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 75,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 75,
                    'char' => 32,
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
                              'type' => 'string',
                              'value' => 'Adapter cannot be opened in read mode',
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 76,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 76,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 76,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 77,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 78,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 80,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'mode',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 80,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 80,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 80,
                'char' => 26,
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
                      'variable' => 'mode',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => 'ab',
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 81,
                        'char' => 26,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 81,
                      'char' => 26,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 82,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 84,
              'char' => 11,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 84,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 84,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'mode',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 85,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 85,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 86,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor. Accepts the name and some options
     *',
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 67,
          'last-line' => 90,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'close',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'result',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 93,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 93,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 95,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'is_resource',
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
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 95,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'handler',
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 95,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 95,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 95,
                    'char' => 37,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 95,
                'char' => 39,
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
                      'variable' => 'result',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fclose',
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
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 96,
                                'char' => 38,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'handler',
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 96,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 96,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 96,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 96,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 96,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 97,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 99,
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
                  'property' => 'handler',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 99,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 99,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 101,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 101,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Closes the stream
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
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 92,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
            'line' => 92,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 91,
          'last-line' => 106,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'process',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'item',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'Item',
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 107,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 107,
              'char' => 40,
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
                  'variable' => 'formatter',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 109,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'formattedMessage',
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 109,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 111,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'is_resource',
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
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 111,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handler',
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 111,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 111,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 111,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 111,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 111,
                'char' => 40,
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
                      'property' => 'handler',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fopen',
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
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 112,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 112,
                                'char' => 49,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 112,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 112,
                            'char' => 49,
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
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 112,
                                'char' => 56,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'mode',
                                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                'line' => 112,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 112,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 112,
                            'char' => 61,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 112,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 112,
                      'char' => 62,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 114,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'is_resource',
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
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 114,
                              'char' => 34,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handler',
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 114,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 114,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 114,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 114,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 114,
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
                          'property' => 'handler',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 115,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 115,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 117,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'UnexpectedValueException',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'sprintf',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'The file \'%s\' cannot be opened with mode \'%s\'',
                                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                    'line' => 119,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                  'line' => 119,
                                  'char' => 70,
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
                                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                      'line' => 120,
                                      'char' => 30,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'name',
                                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                      'line' => 120,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                    'line' => 120,
                                    'char' => 35,
                                  ),
                                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                  'line' => 120,
                                  'char' => 35,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'property-access',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                      'line' => 121,
                                      'char' => 30,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'mode',
                                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                      'line' => 122,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                    'line' => 122,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                                  'line' => 122,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                              'line' => 123,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                            'line' => 123,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 123,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 124,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 125,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 127,
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
                  'variable' => 'formatter',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 127,
                      'char' => 37,
                    ),
                    'name' => 'getFormatter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 127,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 127,
                  'char' => 52,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'formattedMessage',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'formatter',
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 128,
                      'char' => 42,
                    ),
                    'name' => 'format',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'item',
                          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                          'line' => 128,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 128,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 128,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                  'line' => 128,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 130,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'fwrite',
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
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 130,
                        'char' => 21,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'handler',
                        'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                        'line' => 130,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 130,
                      'char' => 29,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 130,
                    'char' => 29,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'formattedMessage',
                      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                      'line' => 130,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                    'line' => 130,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
                'line' => 130,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
              'line' => 131,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Processes the message i.e. writes it to the file
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
            'line' => 108,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
          'line' => 107,
          'last-line' => 132,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
      'line' => 34,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Adapter/Stream.zep',
    'line' => 34,
    'char' => 5,
  ),
);