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
    'file' => '/app/phalcon/Logger/Logger.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Logger',
    'file' => '/app/phalcon/Logger/Logger.zep',
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
        'name' => 'Psr\\Log\\LoggerInterface',
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 13,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
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
        'name' => 'Psr\\Log\\InvalidArgumentException',
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 14,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
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
        'name' => 'Phalcon\\Logger\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 15,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
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
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 16,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
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
        'name' => 'Phalcon\\Logger\\Exception',
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 17,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
    'line' => 51,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Logger
 *
 * This component offers logging capabilities for your application. The
 * component accepts multiple adapters, working also as a multiple logger.
 * Phalcon\\Logger implements PSR-3.
 *
 *```php
 * use Phalcon\\Logger;
 * use Phalcon\\Logger\\Adapter\\Stream;
 *
 * $adapter1 = new Stream(\'/logs/first-log.log\');
 * $adapter2 = new Stream(\'/remote/second-log.log\');
 * $adapter3 = new Stream(\'/manager/third-log.log\');
 *
 * $logger = new Logger(
 *         \'messages\',
 *         [
 *             \'local\'   => $adapter1,
 *             \'remote\'  => $adapter2,
 *             \'manager\' => $adapter3,
 *         ]
 *     );
 *
 * // Log to all adapters
 * $logger->error(\'Something went wrong\');
 *
 * // Log to specific adapters
 * $logger
 *         ->excludeAdapters([\'manager\'])
 *         ->info(\'This does not go to the "manager" logger);
 *```
 *',
    'file' => '/app/phalcon/Logger/Logger.zep',
    'line' => 52,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Logger',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'LoggerInterface',
        'file' => '/app/phalcon/Logger/Logger.zep',
        'line' => 53,
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
          'name' => 'adapters',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 69,
            'char' => 28,
          ),
          'docblock' => '**
     * The adapter stack
     *
     * @var AdapterInterface[]
     *',
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 73,
          'char' => 6,
        ),
        1 => 
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
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 74,
            'char' => 22,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 80,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'excluded',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 81,
            'char' => 28,
          ),
          'docblock' => '**
     * The excluded adapters for this log process
     *
     * @var AdapterInterface[]
     *',
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 88,
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
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 89,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'adapters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 89,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 89,
              'char' => 67,
            ),
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
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 91,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 91,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 93,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 93,
                  'char' => 14,
                ),
                'name' => 'setAdapters',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 93,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 93,
                    'char' => 35,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 93,
                'char' => 36,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 94,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Constructor.
     *
     * @param string name     The name of the logger
     * @param array  adapters The collection of adapters to be used for logging (default [])
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 89,
          'last-line' => 101,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addAdapter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 102,
              'char' => 43,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'adapter',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 102,
                'char' => 70,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 102,
              'char' => 71,
            ),
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
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'adapters',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 104,
                      'char' => 32,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 104,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 104,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 106,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 106,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 107,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Add an adapter to the stack. For processing we use FIFO
     *
     * @param string             name    The name of the adapter
     * @param <AdapterInterface> adapter The adapter to add to the stack
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Logger',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 103,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 102,
          'last-line' => 116,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'alert',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 117,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 117,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 117,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 119,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 119,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ALERT',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 119,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 119,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 119,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 119,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 119,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 119,
                    'char' => 55,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 119,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 119,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 119,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 120,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Action must be taken immediately.
     *
     * Example: Entire website down, database unavailable, etc. This should
     * trigger the SMS alerts and wake you up.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 118,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 117,
          'last-line' => 128,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'critical',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 129,
              'char' => 37,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 129,
                'char' => 57,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 129,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 131,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 131,
                        'char' => 40,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'CRITICAL',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 131,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 131,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 131,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 131,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 131,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 131,
                    'char' => 58,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 131,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 131,
                    'char' => 67,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 131,
                'char' => 68,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Critical conditions.
     *
     * Example: Application component unavailable, unexpected exception.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 130,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 129,
          'last-line' => 138,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'debug',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 139,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 139,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 139,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 141,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 141,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'DEBUG',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 141,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 141,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 141,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 141,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 141,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 141,
                    'char' => 55,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 141,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 141,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 141,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 142,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Detailed debug information.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 140,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 139,
          'last-line' => 149,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'error',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 150,
              'char' => 34,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 150,
                'char' => 54,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 150,
              'char' => 54,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 152,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 152,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ERROR',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 152,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 152,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 152,
                    'char' => 37,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 152,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 152,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 152,
                    'char' => 55,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 152,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 152,
                    'char' => 64,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 152,
                'char' => 65,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 153,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Runtime errors that do not require immediate action but should typically
     * be logged and monitored.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 151,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 150,
          'last-line' => 159,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'emergency',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 160,
              'char' => 38,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 160,
                'char' => 58,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 160,
              'char' => 58,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 162,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 162,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'EMERGENCY',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 162,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 162,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 162,
                    'char' => 41,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 162,
                        'char' => 59,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 162,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 162,
                    'char' => 59,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 162,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 162,
                    'char' => 68,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 162,
                'char' => 69,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 163,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * System is unusable.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 161,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 160,
          'last-line' => 167,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'excludeAdapters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'adapters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 168,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 168,
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
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 170,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'registered',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 170,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 172,
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
                  'variable' => 'registered',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 172,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 172,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 172,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 172,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 179,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'adapters',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 179,
                'char' => 30,
              ),
              'value' => 'name',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'isset',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'registered',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 180,
                        'char' => 32,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 180,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 180,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 180,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'excluded',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'name',
                              'file' => '/app/phalcon/Logger/Logger.zep',
                              'line' => 181,
                              'char' => 40,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 181,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 181,
                          'char' => 48,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 182,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 183,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 185,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 185,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 186,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Exclude certain adapters.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Logger',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 169,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 169,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 169,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 168,
          'last-line' => 194,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAdapter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 195,
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
                  'variable' => 'adapter',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 197,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'adapters',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 197,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 199,
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
                  'variable' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 199,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 199,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 199,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 199,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 201,
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
                    'value' => 'adapter',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 201,
                    'char' => 43,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 201,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 201,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 201,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 201,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 201,
                'char' => 43,
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
                          'value' => 'Adapter does not exist for this logger',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 202,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 202,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 202,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 203,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 205,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'adapter',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 205,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 206,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an adapter from the stack
     *
     * @param string name The name of the adapter
     *
     * @throws <Exception>
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 196,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 196,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 196,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 195,
          'last-line' => 212,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAdapters',
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
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 215,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapters',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 215,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 215,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 216,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the adapter stack array
     *
     * @return AdapterInterface[]
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 214,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 214,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 213,
          'last-line' => 220,
          'char' => 19,
        ),
        10 => 
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
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 223,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 223,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 223,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 224,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the name of the logger
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
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 222,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 222,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 221,
          'last-line' => 232,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'info',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 233,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 233,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 233,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 235,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 235,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'INFO',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 235,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 235,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 235,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 235,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 235,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 235,
                    'char' => 54,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 235,
                      'char' => 63,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 235,
                    'char' => 63,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 235,
                'char' => 64,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 236,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Interesting events.
     *
     * Example: User logs in, SQL logs.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 234,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 233,
          'last-line' => 243,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'log',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'level',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 244,
              'char' => 30,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 244,
              'char' => 39,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 244,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 244,
              'char' => 59,
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
                  'variable' => 'intLevel',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 246,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 248,
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
                  'variable' => 'intLevel',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 248,
                      'char' => 29,
                    ),
                    'name' => 'getLevelNumber',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'level',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 248,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 248,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 248,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 248,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 250,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 250,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'level',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 250,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 250,
                    'char' => 31,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 250,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 250,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 250,
                    'char' => 49,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 250,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 250,
                    'char' => 58,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 250,
                'char' => 59,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 251,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Logs with an arbitrary level.
     *
     * @param mixed  level
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 245,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 244,
          'last-line' => 257,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notice',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 258,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 258,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 258,
              'char' => 55,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 260,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 260,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'NOTICE',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 260,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 260,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 260,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 260,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 260,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 260,
                    'char' => 56,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 260,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 260,
                    'char' => 65,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 260,
                'char' => 66,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 261,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Normal but significant events.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 259,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 258,
          'last-line' => 269,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'removeAdapter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 270,
              'char' => 46,
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
                  'variable' => 'adapters',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 272,
                  'char' => 21,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 274,
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
                  'variable' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 274,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 274,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 274,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 274,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 276,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 276,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'isset',
                  'left' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'adapters',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 276,
                        'char' => 35,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'name',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 276,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 276,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 276,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 276,
                  'char' => 43,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 276,
                'char' => 43,
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
                          'value' => 'Adapter does not exist for this logger',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 277,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 277,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 277,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 278,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 280,
              'char' => 13,
            ),
            3 => 
            array (
              'type' => 'unset',
              'expr' => 
              array (
                'type' => 'array-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'adapters',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 280,
                  'char' => 23,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 280,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 280,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 282,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapters',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 282,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 282,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 284,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 284,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 285,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes an adapter from the stack
     *
     * @param string name The name of the adapter
     *
     * @throws <Logger\\Exception>
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Logger',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 271,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 271,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 271,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 270,
          'last-line' => 291,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAdapters',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'adapters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 292,
              'char' => 48,
            ),
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
                  'property' => 'adapters',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'adapters',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 294,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 294,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 296,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 296,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 297,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the adapters stack overriding what is already there
     *
     * @param array adapters An array of adapters
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'Logger',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 293,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 293,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 293,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 292,
          'last-line' => 306,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'warning',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 307,
              'char' => 36,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 307,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 307,
              'char' => 56,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 309,
                  'char' => 14,
                ),
                'name' => 'addMessage',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 309,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'WARNING',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 309,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 309,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 309,
                    'char' => 39,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'cast',
                      'left' => 'string',
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'message',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 309,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 309,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 309,
                    'char' => 57,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'context',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 309,
                      'char' => 66,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 309,
                    'char' => 66,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 309,
                'char' => 67,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 310,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Exceptional occurrences that are not errors.
     *
     * Example: Use of deprecated APIs, poor use of an API, undesirable things
     * that are not necessarily wrong.
     *
     * @param string message
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 308,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 307,
          'last-line' => 319,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'addMessage',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'level',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 320,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'message',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 320,
              'char' => 60,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'context',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'empty-array',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 320,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 320,
              'char' => 80,
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
                  'variable' => 'adapter',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'key',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'excluded',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 35,
                ),
                3 => 
                array (
                  'variable' => 'levelName',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 46,
                ),
                4 => 
                array (
                  'variable' => 'levels',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 54,
                ),
                5 => 
                array (
                  'variable' => 'item',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 60,
                ),
                6 => 
                array (
                  'variable' => 'registered',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 322,
                  'char' => 72,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 324,
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
                  'variable' => 'registered',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 324,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'adapters',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 324,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 324,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 324,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'excluded',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 325,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'excluded',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 325,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 325,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 325,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 327,
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
                  'type' => 'fcall',
                  'name' => 'count',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'registered',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 327,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 327,
                      'char' => 28,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 327,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 327,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 327,
                'char' => 36,
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
                          'value' => 'No adapters specified',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 328,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 328,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 328,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 331,
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
                  'variable' => 'levels',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 331,
                      'char' => 27,
                    ),
                    'name' => 'getLevels',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 331,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 331,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 333,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'levelName',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 333,
                    'char' => 44,
                  ),
                  'right' => 
                  array (
                    'type' => 'array-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'levels',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 333,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'level',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 333,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 333,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 333,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 333,
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
                      'variable' => 'levelName',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'levels',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 334,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 334,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'CUSTOM',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 334,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 334,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 334,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 334,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 335,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 337,
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
                  'variable' => 'item',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Item',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'message',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 337,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 337,
                        'char' => 36,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'levelName',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 337,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 337,
                        'char' => 47,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'level',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 337,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 337,
                        'char' => 54,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'time',
                          'call-type' => 1,
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 337,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 337,
                        'char' => 62,
                      ),
                      4 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'context',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 337,
                          'char' => 71,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 337,
                        'char' => 71,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 337,
                    'char' => 72,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 337,
                  'char' => 72,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 342,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'registered',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 342,
                'char' => 40,
              ),
              'key' => 'key',
              'value' => 'adapter',
              'reverse' => 0,
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
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'excluded',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 343,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 343,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 343,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 343,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 343,
                    'char' => 37,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'adapter',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 344,
                          'char' => 25,
                        ),
                        'name' => 'process',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'item',
                              'file' => '/app/phalcon/Logger/Logger.zep',
                              'line' => 344,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 344,
                            'char' => 38,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 344,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 345,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 346,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 351,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'excluded',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 351,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 351,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 353,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 353,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 354,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Adds a message to each handler for processing
     *
     * @param int    level
     * @param string message
     *
     * @throws <Logger\\Exception>
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
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 321,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 321,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 320,
          'last-line' => 358,
          'char' => 22,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getLevels',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
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
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 362,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ALERT',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 362,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 362,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'alert',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 362,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 362,
                    'char' => 36,
                  ),
                  1 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 363,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'CRITICAL',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 363,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 363,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'critical',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 363,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 363,
                    'char' => 39,
                  ),
                  2 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 364,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'DEBUG',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 364,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 364,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'debug',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 364,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 364,
                    'char' => 36,
                  ),
                  3 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 365,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'EMERGENCY',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 365,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 365,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'emergency',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 365,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 365,
                    'char' => 40,
                  ),
                  4 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 366,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ERROR',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 366,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 366,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'error',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 366,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 366,
                    'char' => 36,
                  ),
                  5 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 367,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'INFO',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 367,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 367,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'info',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 367,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 367,
                    'char' => 35,
                  ),
                  6 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 368,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'NOTICE',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 368,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 368,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'notice',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 368,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 368,
                    'char' => 37,
                  ),
                  7 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 369,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'WARNING',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 369,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 369,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'warning',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 369,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 369,
                    'char' => 38,
                  ),
                  8 => 
                  array (
                    'key' => 
                    array (
                      'type' => 'static-constant-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'self',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 370,
                        'char' => 29,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'CUSTOM',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 370,
                        'char' => 29,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 370,
                      'char' => 29,
                    ),
                    'value' => 
                    array (
                      'type' => 'string',
                      'value' => 'custom',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 371,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 371,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 371,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 372,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns an array of log levels with integer to string conversion
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 360,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 360,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 359,
          'last-line' => 378,
          'char' => 22,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'method',
          'name' => 'getLevelNumber',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'level',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 379,
              'char' => 42,
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
                  'variable' => 'levelName',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 381,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'numberLevel',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 381,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'levels',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 381,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 383,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'level',
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 383,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 383,
                  'char' => 27,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 383,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 383,
                'char' => 36,
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
                      'variable' => 'levelName',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'strtolower',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'level',
                              'file' => '/app/phalcon/Logger/Logger.zep',
                              'line' => 384,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 384,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 384,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 384,
                      'char' => 46,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'levels',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'array_flip',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Logger/Logger.zep',
                                'line' => 385,
                                'char' => 45,
                              ),
                              'name' => 'getLevels',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Logger/Logger.zep',
                              'line' => 385,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 385,
                            'char' => 57,
                          ),
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 385,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 385,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 387,
                  'char' => 14,
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
                      'value' => 'numberLevel',
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 387,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'levels',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 387,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'levelName',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 387,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 387,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 387,
                    'char' => 53,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'numberLevel',
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 388,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 389,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 390,
                  'char' => 9,
                ),
              ),
              'elseif_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'is_numeric',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'level',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 390,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 390,
                        'char' => 34,
                      ),
                    ),
                    'file' => '/app/phalcon/Logger/Logger.zep',
                    'line' => 390,
                    'char' => 36,
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
                          'variable' => 'levels',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Logger/Logger.zep',
                              'line' => 391,
                              'char' => 31,
                            ),
                            'name' => 'getLevels',
                            'call-type' => 1,
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 391,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 391,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 393,
                      'char' => 14,
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
                          'value' => 'numberLevel',
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 393,
                          'char' => 49,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'levels',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 393,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'level',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 393,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 393,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Logger/Logger.zep',
                        'line' => 393,
                        'char' => 49,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'numberLevel',
                            'file' => '/app/phalcon/Logger/Logger.zep',
                            'line' => 394,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Logger/Logger.zep',
                          'line' => 395,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Logger/Logger.zep',
                      'line' => 396,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 398,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 398,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'static-constant-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'self',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 398,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'CUSTOM',
                  'file' => '/app/phalcon/Logger/Logger.zep',
                  'line' => 398,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 398,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Logger/Logger.zep',
              'line' => 399,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Converts the level from string/word to an integer
     *
     * @param string|int level
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
                'file' => '/app/phalcon/Logger/Logger.zep',
                'line' => 380,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 380,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 379,
          'last-line' => 400,
          'char' => 20,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'ALERT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 54,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 55,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'CRITICAL',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 55,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 56,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'CUSTOM',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 56,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 57,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'DEBUG',
          'default' => 
          array (
            'type' => 'int',
            'value' => '7',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 57,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 58,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'EMERGENCY',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 58,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 59,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'ERROR',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 59,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 60,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'INFO',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 60,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 61,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'NOTICE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 61,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 62,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'WARNING',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Logger/Logger.zep',
            'line' => 62,
            'char' => 24,
          ),
          'file' => '/app/phalcon/Logger/Logger.zep',
          'line' => 68,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Logger/Logger.zep',
      'line' => 52,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Logger/Logger.zep',
    'line' => 52,
    'char' => 5,
  ),
);