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
    'file' => '/app/phalcon/Db/Profiler.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Db',
    'file' => '/app/phalcon/Db/Profiler.zep',
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
        'name' => 'Phalcon\\Db\\Profiler\\Item',
        'file' => '/app/phalcon/Db/Profiler.zep',
        'line' => 13,
        'char' => 29,
      ),
    ),
    'file' => '/app/phalcon/Db/Profiler.zep',
    'line' => 65,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Instances of Phalcon\\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in milliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 * ```php
 * use Phalcon\\Db\\Profiler;
 * use Phalcon\\Events\\Event;
 * use Phalcon\\Events\\Manager;
 *
 * $profiler = new Profiler();
 * $eventsManager = new Manager();
 *
 * $eventsManager->attach(
 *     "db",
 *     function (Event $event, $connection) use ($profiler) {
 *         if ($event->getType() === "beforeQuery") {
 *             $sql = $connection->getSQLStatement();
 *
 *             // Start a profile with the active connection
 *             $profiler->startProfile($sql);
 *         }
 *
 *         if ($event->getType() === "afterQuery") {
 *             // Stop the active profile
 *             $profiler->stopProfile();
 *         }
 *     }
 * );
 *
 * // Set the event manager on the connection
 * $connection->setEventsManager($eventsManager);
 *
 *
 * $sql = "SELECT buyer_name, quantity, product_name
 * FROM buyers LEFT JOIN products ON
 * buyers.pid=products.id";
 *
 * // Execute a SQL statement
 * $connection->query($sql);
 *
 * // Get the last profile in the profiler
 * $profile = $profiler->getLastProfile();
 *
 * echo "SQL Statement: ", $profile->getSQLStatement(), "\\n";
 * echo "Start Time: ", $profile->getInitialTime(), "\\n";
 * echo "Final Time: ", $profile->getFinalTime(), "\\n";
 * echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\\n";
 * ```
 *',
    'file' => '/app/phalcon/Db/Profiler.zep',
    'line' => 66,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Profiler',
    'abstract' => 0,
    'final' => 0,
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
          'name' => 'activeProfile',
          'docblock' => '**
     * Active Phalcon\\Db\\Profiler\\Item
     *
     * @var Phalcon\\Db\\Profiler\\Item
     *',
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 79,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'allProfiles',
          'docblock' => '**
     * All the Phalcon\\Db\\Profiler\\Item in the active profile
     *
     * @var \\Phalcon\\Db\\Profiler\\Item[]
     *',
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 86,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'totalSeconds',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 87,
            'char' => 31,
          ),
          'docblock' => '**
     * Total time spent by all profiles to complete
     *
     * @var float
     *',
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 91,
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
          'name' => 'getLastProfile',
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
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 94,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 94,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 94,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 95,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the last profile executed in the profiler
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
                  'value' => 'Item',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 93,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 93,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 93,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 92,
          'last-line' => 99,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNumberTotalStatements',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
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
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 102,
                        'char' => 27,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'allProfiles',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 102,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 102,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 102,
                    'char' => 39,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 102,
                'char' => 40,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the total number of SQL statements processed
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
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 101,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 100,
          'last-line' => 107,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTotalElapsedSeconds',
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
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 110,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'totalSeconds',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 110,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 110,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 111,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the total time in seconds spent by the profiles
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'double',
                'mandatory' => 0,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 109,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 108,
          'last-line' => 115,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getProfiles',
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
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 118,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'allProfiles',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 118,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 118,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns all the processed profiles
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
                  'value' => 'Item',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 117,
                  'char' => 5,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 117,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 117,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 116,
          'last-line' => 123,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'reset',
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
                  'property' => 'allProfiles',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 126,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 126,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 128,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 128,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 129,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resets the profiler, cleaning up all the profiles
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
                  'value' => 'Profiler',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 125,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 125,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 125,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 124,
          'last-line' => 133,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'startProfile',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlStatement',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 134,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlVariables',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 134,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 134,
              'char' => 78,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'sqlBindTypes',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 134,
                'char' => 103,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 134,
              'char' => 103,
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
                  'variable' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 136,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 138,
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
                  'variable' => 'activeProfile',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Item',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 138,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 138,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 140,
              'char' => 21,
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
                  'value' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 140,
                  'char' => 23,
                ),
                'name' => 'setSqlStatement',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sqlStatement',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 140,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 140,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 140,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 142,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sqlVariables',
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 142,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 142,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 142,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 142,
                'char' => 41,
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
                      'value' => 'activeProfile',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 143,
                      'char' => 27,
                    ),
                    'name' => 'setSqlVariables',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sqlVariables',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 143,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 143,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 143,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 144,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 146,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sqlBindTypes',
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 146,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 146,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 146,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 146,
                'char' => 41,
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
                      'value' => 'activeProfile',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 147,
                      'char' => 27,
                    ),
                    'name' => 'setSqlBindTypes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sqlBindTypes',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 147,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 147,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 147,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 150,
              'char' => 21,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 150,
                  'char' => 23,
                ),
                'name' => 'setInitialTime',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'microtime',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Db/Profiler.zep',
                            'line' => 150,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 150,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 150,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 150,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 150,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 152,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 152,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 152,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'beforeStartProfile',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 152,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 152,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 152,
                'char' => 52,
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
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 153,
                      'char' => 18,
                    ),
                    'name' => 'beforeStartProfile',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeProfile',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 153,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 153,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 153,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 154,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 156,
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
                  'property' => 'activeProfile',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeProfile',
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 156,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 156,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 158,
              'char' => 14,
            ),
            8 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 158,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Starts the profile of a SQL sentence
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
                  'value' => 'Profiler',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 135,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 135,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 135,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 134,
          'last-line' => 163,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'stopProfile',
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
                  'variable' => 'finalTime',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 166,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'initialTime',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 166,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 166,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 168,
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
                  'variable' => 'finalTime',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'microtime',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 168,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 168,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 168,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 168,
                  'char' => 40,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'activeProfile',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'Item',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 169,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 169,
                        'char' => 41,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'activeProfile',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 169,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 169,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 169,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 169,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 171,
              'char' => 21,
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
                  'value' => 'activeProfile',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 171,
                  'char' => 23,
                ),
                'name' => 'setFinalTime',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'finalTime',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 171,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 171,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 171,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 173,
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
                  'variable' => 'initialTime',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'activeProfile',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 173,
                      'char' => 41,
                    ),
                    'name' => 'getInitialTime',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 173,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 173,
                  'char' => 58,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'totalSeconds',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 174,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'totalSeconds',
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 174,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 174,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'finalTime',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 174,
                          'char' => 66,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'initialTime',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 174,
                          'char' => 79,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 174,
                        'char' => 79,
                      ),
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 174,
                      'char' => 80,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 174,
                    'char' => 80,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 174,
                  'char' => 80,
                ),
                2 => 
                array (
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'allProfiles',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'activeProfile',
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 175,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 175,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 177,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'method_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 177,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 177,
                    'char' => 30,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'afterEndProfile',
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 177,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 177,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 177,
                'char' => 49,
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
                      'file' => '/app/phalcon/Db/Profiler.zep',
                      'line' => 178,
                      'char' => 18,
                    ),
                    'name' => 'afterEndProfile',
                    'call-type' => 3,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'activeProfile',
                          'file' => '/app/phalcon/Db/Profiler.zep',
                          'line' => 178,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Db/Profiler.zep',
                        'line' => 178,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Db/Profiler.zep',
                    'line' => 178,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 179,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 181,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 181,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Db/Profiler.zep',
              'line' => 182,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Stops the active profile
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
                  'value' => 'Profiler',
                  'file' => '/app/phalcon/Db/Profiler.zep',
                  'line' => 165,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Db/Profiler.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Db/Profiler.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Db/Profiler.zep',
          'line' => 164,
          'last-line' => 183,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Db/Profiler.zep',
      'line' => 66,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Db/Profiler.zep',
    'line' => 66,
    'char' => 5,
  ),
);