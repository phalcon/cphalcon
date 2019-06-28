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
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger\\Adapter',
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
        'name' => 'LogicException',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 13,
        'char' => 19,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Logger',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 14,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Adapter',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 15,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Exception',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 16,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
        'name' => 'Phalcon\\Logger\\Formatter\\FormatterInterface',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 17,
        'char' => 48,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Logger\\Item',
        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
        'line' => 18,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
    'line' => 42,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger\\Adapter\\Syslog
 *
 * Sends logs to the system logger
 *
 * ```php
 * use Phalcon\\Logger;
 * use Phalcon\\Logger\\Adapter\\Syslog;
 *
 * // LOG_USER is the only valid log type under Windows operating systems
 * $logger = new Syslog(
 *     "ident",
 *     [
 *         "option"   => LOG_CONS | LOG_NDELAY | LOG_PID,
 *         "facility" => LOG_USER,
 *     ]
 * );
 *
 * $logger->log("This is a message");
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *```
 *',
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
    'line' => 43,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Syslog',
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
          'name' => 'defaultFormatter',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'Syslog',
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 50,
            'char' => 40,
          ),
          'docblock' => '**
     * Name of the default formatter class
     *
     * @var string
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 54,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'facility',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 55,
            'char' => 27,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 59,
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
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 60,
            'char' => 22,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 64,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'opened',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 65,
            'char' => 29,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 69,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'option',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 70,
            'char' => 25,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 74,
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
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 75,
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
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 75,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 75,
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
                  'variable' => 'option',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 77,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'facility',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 77,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 79,
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
                  'value' => 'option',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 79,
                  'char' => 42,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'options',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 79,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'option',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 79,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 79,
                  'char' => 42,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 79,
                'char' => 42,
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
                      'variable' => 'option',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'LOG_ODELAY',
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 80,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 80,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 81,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 83,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'facility',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 83,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'options',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 83,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'facility',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 83,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 83,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 83,
                  'char' => 47,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 83,
                'char' => 47,
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
                      'variable' => 'facility',
                      'expr' => 
                      array (
                        'type' => 'constant',
                        'value' => 'LOG_USER',
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 84,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 84,
                      'char' => 36,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 87,
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
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 87,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 87,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'facility',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'facility',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 88,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 88,
                  'char' => 38,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'option',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'option',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 89,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 89,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 90,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Logger\\Adapter\\Syslog constructor
     *',
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 75,
          'last-line' => 94,
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
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 97,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'opened',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 97,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 97,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 97,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 98,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 99,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 101,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'closelog',
                'call-type' => 1,
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 101,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 102,
              'char' => 5,
            ),
          ),
          'docblock' => '**
      * Closes the logger
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
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 96,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 96,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 95,
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
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 107,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'facility',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 27,
                ),
                2 => 
                array (
                  'variable' => 'formatter',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'level',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 45,
                ),
                4 => 
                array (
                  'variable' => 'message',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 54,
                ),
                5 => 
                array (
                  'variable' => 'option',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 62,
                ),
                6 => 
                array (
                  'variable' => 'result',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 109,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 110,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'opened',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 110,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 112,
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
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 112,
                      'char' => 30,
                    ),
                    'name' => 'getFormatter',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 112,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 112,
                  'char' => 45,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'message',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'formatter',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 113,
                      'char' => 35,
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
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 113,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 113,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 113,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 113,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 115,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'message',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 115,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 115,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 115,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 115,
                'char' => 37,
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
                          'value' => 'The formatted message is not valid',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 116,
                          'char' => 67,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 116,
                        'char' => 67,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 116,
                    'char' => 68,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 117,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 119,
              'char' => 11,
            ),
            4 => 
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
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 119,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 119,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 119,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 119,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'facility',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 120,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'facility',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 120,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 120,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 120,
                  'char' => 38,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'option',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 121,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'option',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 121,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 121,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 121,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 123,
              'char' => 11,
            ),
            5 => 
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
                    'name' => 'openlog',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 123,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 123,
                        'char' => 34,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'option',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 123,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 123,
                        'char' => 42,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'facility',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 123,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 123,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 123,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 123,
                  'char' => 53,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 125,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'list',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'result',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 125,
                    'char' => 20,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 125,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 125,
                'char' => 22,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'LogicException',
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
                                'value' => 'Cannot open syslog for name [%s] and facility [%s]',
                                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                                'line' => 128,
                                'char' => 71,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                              'line' => 128,
                              'char' => 71,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                                'line' => 129,
                                'char' => 25,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                              'line' => 129,
                              'char' => 25,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'facility',
                                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                                'line' => 131,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                              'line' => 131,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 132,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 132,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 132,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 133,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 135,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'opened',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 135,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 135,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'opened',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'opened',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 136,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 136,
                  'char' => 34,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'level',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 137,
                      'char' => 33,
                    ),
                    'name' => 'logLevelToSyslog',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'message',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 137,
                            'char' => 58,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '1',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 137,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 137,
                          'char' => 61,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 137,
                        'char' => 61,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 137,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 137,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 139,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'syslog',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'level',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 139,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 139,
                    'char' => 21,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 139,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '1',
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 139,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 139,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 139,
                    'char' => 33,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 139,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 140,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Processes the message i.e. writes it to the syslog
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 108,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 107,
          'last-line' => 144,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'logLevelToSyslog',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'level',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 145,
              'char' => 51,
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
                  'variable' => 'result',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 147,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 148,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'levels',
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 148,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 150,
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
                  'variable' => 'levels',
                  'expr' => 
                  array (
                    'type' => 'array',
                    'left' => 
                    array (
                      0 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 151,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ALERT',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 151,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 151,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_ALERT',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 151,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 151,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 152,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'CRITICAL',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 152,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 152,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_CRIT',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 152,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 152,
                        'char' => 41,
                      ),
                      2 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 153,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'CUSTOM',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 153,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 153,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_ERR',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 153,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 153,
                        'char' => 40,
                      ),
                      3 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 154,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'DEBUG',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 154,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 154,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_DEBUG',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 154,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 154,
                        'char' => 42,
                      ),
                      4 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 155,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'EMERGENCY',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 155,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 155,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_EMERG',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 155,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 155,
                        'char' => 42,
                      ),
                      5 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 156,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ERROR',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 156,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 156,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_ERR',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 156,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 156,
                        'char' => 40,
                      ),
                      6 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 157,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'INFO',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 157,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 157,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_INFO',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 157,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 157,
                        'char' => 41,
                      ),
                      7 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 158,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'NOTICE',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 158,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 158,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_NOTICE',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 158,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 158,
                        'char' => 43,
                      ),
                      8 => 
                      array (
                        'key' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Logger',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 159,
                            'char' => 31,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'WARNING',
                            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                            'line' => 159,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 159,
                          'char' => 31,
                        ),
                        'value' => 
                        array (
                          'type' => 'constant',
                          'value' => 'LOG_WARNING',
                          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                          'line' => 160,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 160,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 160,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 160,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 162,
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
                    'value' => 'result',
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 162,
                    'char' => 41,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'levels',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 162,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'level',
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 162,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                    'line' => 162,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 162,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 162,
                'char' => 41,
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
                        'type' => 'constant',
                        'value' => 'LOG_ERR',
                        'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                        'line' => 163,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                      'line' => 163,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                  'line' => 164,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 166,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'result',
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 166,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Translates a Logger level to a Syslog level
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
                'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
                'line' => 146,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
            'line' => 146,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
          'line' => 145,
          'last-line' => 168,
          'char' => 20,
        ),
      ),
      'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
      'line' => 43,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Adapter/Syslog.zep',
    'line' => 43,
    'char' => 5,
  ),
);