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
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 14,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction\\Failed',
        'alias' => 'TxFailed',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 15,
        'char' => 53,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 16,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\TransactionInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 17,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
    'line' => 62,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if
 * they can all succeed as one atomic action. Phalcon\\Transaction is intended to
 * be used with Phalcon_Model_Base. Phalcon Transactions should be created using
 * Phalcon\\Transaction\\Manager.
 *
 * ```php
 * use Phalcon\\Mvc\\Model\\Transaction\\Failed;
 * use Phalcon\\Mvc\\Model\\Transaction\\Manager;
 *
 * try {
 *     $manager = new Manager();
 *
 *     $transaction = $manager->get();
 *
 *     $robot = new Robots();
 *
 *     $robot->setTransaction($transaction);
 *
 *     $robot->name       = "WALL·E";
 *     $robot->created_at = date("Y-m-d");
 *
 *     if ($robot->save() === false) {
 *         $transaction->rollback("Can\'t save robot");
 *     }
 *
 *     $robotPart = new RobotParts();
 *
 *     $robotPart->setTransaction($transaction);
 *
 *     $robotPart->type = "head";
 *
 *     if ($robotPart->save() === false) {
 *         $transaction->rollback("Can\'t save robot part");
 *     }
 *
 *     $transaction->commit();
 * } catch(Failed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 * ```
 *',
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
    'line' => 63,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Transaction',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'TransactionInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
        'line' => 64,
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
          'name' => 'activeTransaction',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 65,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 67,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'connection',
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 69,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'isNewTransaction',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 69,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 71,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'manager',
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 73,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'messages',
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 75,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'rollbackRecord',
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 77,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'rollbackOnAbort',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 77,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 79,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'rollbackThrowException',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 79,
            'char' => 45,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 83,
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
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 84,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 84,
              'char' => 56,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'autoBegin',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 84,
                'char' => 80,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 84,
              'char' => 80,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'service',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'db',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 84,
                'char' => 101,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 84,
              'char' => 101,
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
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 86,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 88,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'messages',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 88,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 88,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 90,
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
                  'variable' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 90,
                      'char' => 36,
                    ),
                    'name' => 'get',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'service',
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 90,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 90,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 90,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 90,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 92,
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
                  'property' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 92,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 92,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 94,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'autoBegin',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 94,
                'char' => 22,
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
                      'value' => 'connection',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 95,
                      'char' => 24,
                    ),
                    'name' => 'begin',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 95,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 96,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 97,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Transaction constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 85,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 84,
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
          'name' => 'begin',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 104,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 104,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 104,
                  'char' => 33,
                ),
                'name' => 'begin',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 104,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 105,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Starts the transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 102,
          'last-line' => 109,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'commit',
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
                  'variable' => 'manager',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 112,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
                  'variable' => 'manager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 114,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 114,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 114,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 114,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 116,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'manager',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 116,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 116,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 116,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 116,
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
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 117,
                      'char' => 21,
                    ),
                    'name' => 'notifyCommit',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 117,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 117,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 117,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 118,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 120,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 120,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 120,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 120,
                  'char' => 33,
                ),
                'name' => 'commit',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 120,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 121,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Commits the transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 111,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 111,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 110,
          'last-line' => 125,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConnection',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 128,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'rollbackOnAbort',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 128,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 128,
                'char' => 34,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'connection_aborted',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 129,
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
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 130,
                          'char' => 22,
                        ),
                        'name' => 'rollback',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'The request was aborted',
                              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                              'line' => 130,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                            'line' => 130,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 130,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 131,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 132,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 134,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 134,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'connection',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 134,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 134,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 135,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the connection related to transaction
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
                  'value' => '\\Phalcon\\Db\\AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 127,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 127,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 127,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 126,
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
          'name' => 'getMessages',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 142,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'messages',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 142,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 142,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 143,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns validations messages from last save try
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 141,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 141,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 140,
          'last-line' => 147,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isManaged',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 150,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 150,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 150,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 150,
                  'char' => 38,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 150,
                  'char' => 46,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 150,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 151,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether transaction is managed by a transaction manager
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 149,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 149,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 148,
          'last-line' => 155,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isValid',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 158,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 158,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 158,
                  'char' => 33,
                ),
                'name' => 'isUnderTransaction',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 158,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether internal connection is under an active transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 157,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 157,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 156,
          'last-line' => 163,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackMessage',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 164,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 164,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackRecord',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 164,
                'char' => 91,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 164,
                'char' => 99,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 164,
              'char' => 99,
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
                  'variable' => 'manager',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 166,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 166,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
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
                  'variable' => 'manager',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 168,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 168,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 168,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 168,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 170,
              'char' => 10,
            ),
            2 => 
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
                    'value' => 'manager',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 170,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 170,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 170,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 170,
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
                      'value' => 'manager',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 171,
                      'char' => 21,
                    ),
                    'name' => 'notifyRollback',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 171,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 171,
                        'char' => 41,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 171,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 172,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 174,
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
                  'variable' => 'connection',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 174,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 174,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 174,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 174,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 176,
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
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'connection',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 176,
                    'char' => 32,
                  ),
                  'name' => 'rollback',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 176,
                  'char' => 44,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 176,
                'char' => 44,
              ),
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
                      'type' => 'variable',
                      'value' => 'rollbackMessage',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 177,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 177,
                    'char' => 33,
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
                          'variable' => 'rollbackMessage',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'Transaction aborted',
                            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                            'line' => 178,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 178,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 179,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 181,
                  'char' => 14,
                ),
                1 => 
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
                        'value' => 'rollbackRecord',
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 181,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 181,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 181,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 181,
                    'char' => 48,
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
                          'property' => 'rollbackRecord',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'rollbackRecord',
                            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                            'line' => 182,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                          'line' => 182,
                          'char' => 58,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 183,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 185,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 185,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rollbackThrowException',
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 185,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 185,
                    'char' => 45,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'TxFailed',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'rollbackMessage',
                              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                              'line' => 186,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                            'line' => 186,
                            'char' => 51,
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
                                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                                'line' => 186,
                                'char' => 58,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'rollbackRecord',
                                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                                'line' => 186,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                              'line' => 186,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                            'line' => 186,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                        'line' => 186,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                      'line' => 187,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 190,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 190,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 191,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rollbacks the transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 164,
          'last-line' => 195,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setIsNewTransaction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'isNew',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 196,
              'char' => 51,
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
                  'property' => 'isNewTransaction',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'isNew',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 198,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 198,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 199,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if is a reused transaction or new once
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 197,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 196,
          'last-line' => 203,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRollbackOnAbort',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackOnAbort',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 204,
              'char' => 60,
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
                  'property' => 'rollbackOnAbort',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'rollbackOnAbort',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 206,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 206,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 207,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets flag to rollback on abort the HTTP connection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 205,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 204,
          'last-line' => 211,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRollbackedRecord',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 212,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 212,
              'char' => 64,
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
                  'property' => 'rollbackRecord',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'record',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 214,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 214,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 215,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets object which generates rollback action
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 213,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 212,
          'last-line' => 219,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTransactionManager',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'manager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ManagerInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 220,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 220,
              'char' => 69,
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
                  'property' => 'manager',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'manager',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 222,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 222,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 223,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets transaction manager related to the transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 221,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 220,
          'last-line' => 227,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'throwRollbackException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'status',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 228,
              'char' => 55,
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
                  'property' => 'rollbackThrowException',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'status',
                    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                    'line' => 230,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 230,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 232,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 232,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
              'line' => 233,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Enables throwing exception
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
                  'value' => 'TransactionInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                  'line' => 229,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
                'line' => 229,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
            'line' => 229,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
          'line' => 228,
          'last-line' => 234,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
      'line' => 63,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction.zep',
    'line' => 63,
    'char' => 5,
  ),
);