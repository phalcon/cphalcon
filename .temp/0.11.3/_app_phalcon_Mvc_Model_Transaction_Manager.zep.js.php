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
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model\\Transaction',
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'name' => 'Phalcon\\Di',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 13,
        'char' => 15,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 15,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 16,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction\\Exception',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 17,
        'char' => 44,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 18,
        'char' => 34,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Mvc\\Model\\TransactionInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 19,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
    'line' => 67,
    'char' => 2,
  ),
  9 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Transaction\\Manager
 *
 * A transaction acts on a single database connection. If you have multiple
 * class-specific databases, the transaction will not protect interaction among
 * them.
 *
 * This class manages the objects that compose a transaction.
 * A transaction produces a unique connection that is passed to every object
 * part of the transaction.
 *
 * ```php
 * use Phalcon\\Mvc\\Model\\Transaction\\Failed;
 * use Phalcon\\Mvc\\Model\\Transaction\\Manager;
 *
 * try {
 *    $transactionManager = new Manager();
 *
 *    $transaction = $transactionManager->get();
 *
 *    $robot = new Robots();
 *
 *    $robot->setTransaction($transaction);
 *
 *    $robot->name       = "WALL·E";
 *    $robot->created_at = date("Y-m-d");
 *
 *    if ($robot->save() === false) {
 *        $transaction->rollback("Can\'t save robot");
 *    }
 *
 *    $robotPart = new RobotParts();
 *
 *    $robotPart->setTransaction($transaction);
 *
 *    $robotPart->type = "head";
 *
 *    if ($robotPart->save() === false) {
 *        $transaction->rollback("Can\'t save robot part");
 *    }
 *
 *    $transaction->commit();
 * } catch (Failed $e) {
 *    echo "Failed, reason: ", $e->getMessage();
 * }
 *```
 *',
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
    'line' => 68,
    'char' => 5,
  ),
  10 => 
  array (
    'type' => 'class',
    'name' => 'Manager',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ManagerInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 68,
        'char' => 42,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
        'line' => 69,
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
          'name' => 'container',
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 72,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'initialized',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 72,
            'char' => 34,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 74,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'number',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 74,
            'char' => 25,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 76,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'rollbackPendent',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 76,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 78,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'service',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'db',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 78,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 82,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'transactions',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 83,
            'char' => 32,
          ),
          'docblock' => '**
     * @var array
     *',
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 87,
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 88,
                'char' => 55,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 88,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 88,
              'char' => 63,
            ),
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
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 90,
                  'char' => 23,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 90,
                'char' => 23,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'scall',
                        'dynamic-class' => 0,
                        'class' => 'Di',
                        'dynamic' => 0,
                        'name' => 'getDefault',
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 91,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 91,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 92,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 94,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 94,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 94,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 96,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 96,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 96,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 96,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 96,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 96,
                'char' => 48,
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
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Exception',
                          'dynamic' => 0,
                          'name' => 'containerServiceNotFound',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'the services related to the ORM',
                                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                'line' => 100,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                              'line' => 100,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 101,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 101,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 101,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 102,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 103,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Transaction\\Manager constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 89,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 88,
          'last-line' => 107,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'collectTransactions',
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
                  'variable' => 'transactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 110,
                  'char' => 25,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 112,
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
                  'variable' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 112,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactions',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 112,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 112,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 112,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 114,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'transactions',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 114,
                'char' => 31,
              ),
              'value' => '_',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property-decr',
                      'variable' => 'this',
                      'property' => 'number',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 115,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 116,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 118,
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
                  'property' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 118,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 118,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 119,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Remove all the transactions from the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 109,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 108,
          'last-line' => 123,
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
                  'variable' => 'transactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 126,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'transaction',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 126,
                  'char' => 38,
                ),
                2 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 126,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 128,
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
                  'variable' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 128,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactions',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 128,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 128,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 128,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 130,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'transactions',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 130,
                'char' => 41,
              ),
              'value' => 'transaction',
              'reverse' => 0,
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
                      'variable' => 'connection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'transaction',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 131,
                          'char' => 42,
                        ),
                        'name' => 'getConnection',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 131,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 131,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 133,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 133,
                      'char' => 27,
                    ),
                    'name' => 'isUnderTransaction',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 133,
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
                          'value' => 'connection',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 134,
                          'char' => 28,
                        ),
                        'name' => 'commit',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 134,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 135,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 136,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 137,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Commits active transactions within the manager
     *',
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 124,
          'last-line' => 142,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'autoBegin',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 143,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 143,
              'char' => 46,
            ),
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
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 145,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'initialized',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 145,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 145,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 145,
                'char' => 31,
              ),
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
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 146,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'rollbackPendent',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 146,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 146,
                    'char' => 38,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'fcall',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'register_shutdown_function',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'array',
                              'left' => 
                              array (
                                0 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                    'line' => 149,
                                    'char' => 29,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                  'line' => 149,
                                  'char' => 29,
                                ),
                                1 => 
                                array (
                                  'value' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'rollbackPendent',
                                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                    'line' => 151,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                  'line' => 151,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                              'line' => 152,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 152,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 152,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 153,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 155,
                  'char' => 15,
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
                      'property' => 'initialized',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 155,
                        'char' => 41,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 155,
                      'char' => 41,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 156,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 158,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 158,
                  'char' => 21,
                ),
                'name' => 'getOrCreateTransaction',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'autoBegin',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 158,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 158,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 158,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 159,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a new \\Phalcon\\Mvc\\Model\\Transaction or an already created once
     * This method registers a shutdown function to rollback active connections
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 144,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 144,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 144,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 143,
          'last-line' => 163,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDbService',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 166,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'service',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 166,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 166,
                'char' => 29,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 167,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the database service used to isolate the transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 165,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 165,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 164,
          'last-line' => 171,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 174,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 174,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 174,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 175,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the dependency injection container
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 173,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 173,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 173,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 172,
          'last-line' => 179,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getOrCreateTransaction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'autoBegin',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 180,
                'char' => 65,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 180,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 182,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'transaction',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 182,
                  'char' => 35,
                ),
                2 => 
                array (
                  'variable' => 'transactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 182,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 184,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 184,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 184,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 184,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 184,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 184,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 184,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 186,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 186,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 186,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 186,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 186,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 186,
                'char' => 48,
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
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Exception',
                          'dynamic' => 0,
                          'name' => 'containerServiceNotFound',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'the services related to the ORM',
                                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                'line' => 190,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                              'line' => 190,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 191,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 191,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 191,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 192,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 194,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 194,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'number',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 194,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 194,
                'char' => 25,
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
                      'variable' => 'transactions',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 195,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'transactions',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 195,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 195,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 195,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 197,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'transactions',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 197,
                    'char' => 53,
                  ),
                  'value' => 'transaction',
                  'reverse' => 1,
                  'statements' => 
                  array (
                    0 => 
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
                            'value' => 'transaction',
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 198,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 198,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 198,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 198,
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
                              'value' => 'transaction',
                              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                              'line' => 199,
                              'char' => 33,
                            ),
                            'name' => 'setIsNewTransaction',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'bool',
                                  'value' => 'false',
                                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                  'line' => 199,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                                'line' => 199,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 199,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 201,
                          'char' => 26,
                        ),
                        1 => 
                        array (
                          'type' => 'return',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'transaction',
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 201,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 202,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 203,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 204,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 206,
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
                  'variable' => 'transaction',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Transaction',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 206,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 206,
                        'char' => 52,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'autoBegin',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 206,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 206,
                        'char' => 63,
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
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 206,
                            'char' => 70,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'service',
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 206,
                            'char' => 78,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 206,
                          'char' => 78,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 206,
                        'char' => 78,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 206,
                    'char' => 79,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 206,
                  'char' => 79,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 207,
              'char' => 23,
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
                  'value' => 'transaction',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 207,
                  'char' => 25,
                ),
                'name' => 'setTransactionManager',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 207,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 207,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 207,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 209,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-append',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'transaction',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 209,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 209,
                  'char' => 47,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property-incr',
                  'variable' => 'this',
                  'property' => 'number',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 209,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 211,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'transaction',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 211,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 212,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Create/Returns a new transaction or an existing one
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 181,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 181,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 181,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 180,
          'last-line' => 217,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRollbackPendent',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 220,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'rollbackPendent',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 220,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 220,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 221,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the transaction manager is registering a shutdown function to
     * clean up pendent transactions
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 219,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 219,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 218,
          'last-line' => 225,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'greater',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 228,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'number',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 228,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 228,
                  'char' => 29,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 228,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 228,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 229,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks whether the manager has an active transaction
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 227,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 227,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 226,
          'last-line' => 233,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyCommit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 234,
                'char' => 67,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 234,
              'char' => 68,
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 236,
                  'char' => 14,
                ),
                'name' => 'collectTransaction',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transaction',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 236,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 236,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 236,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 237,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Notifies the manager about a committed transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 235,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 234,
          'last-line' => 241,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'notifyRollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 242,
                'char' => 69,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 242,
              'char' => 70,
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 244,
                  'char' => 14,
                ),
                'name' => 'collectTransaction',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transaction',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 244,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 244,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 244,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 245,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Notifies the manager about a rollbacked transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 243,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 242,
          'last-line' => 250,
          'char' => 19,
        ),
        11 => 
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
              'name' => 'collect',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 251,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 251,
              'char' => 49,
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
                  'variable' => 'transactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 253,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'transaction',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 253,
                  'char' => 38,
                ),
                2 => 
                array (
                  'variable' => 'connection',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 253,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 255,
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
                  'variable' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 255,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transactions',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 255,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 255,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 255,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 257,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'transactions',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 257,
                'char' => 41,
              ),
              'value' => 'transaction',
              'reverse' => 0,
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
                      'variable' => 'connection',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'transaction',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 258,
                          'char' => 42,
                        ),
                        'name' => 'getConnection',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 258,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 258,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 260,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'connection',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 260,
                      'char' => 27,
                    ),
                    'name' => 'isUnderTransaction',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 260,
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
                          'value' => 'connection',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 261,
                          'char' => 28,
                        ),
                        'name' => 'rollback',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 261,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 262,
                      'char' => 26,
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
                          'value' => 'connection',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 262,
                          'char' => 28,
                        ),
                        'name' => 'close',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 262,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 263,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 265,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'collect',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 265,
                    'char' => 24,
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
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 266,
                          'char' => 22,
                        ),
                        'name' => 'collectTransaction',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'transaction',
                              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                              'line' => 266,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 266,
                            'char' => 53,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                        'line' => 266,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 267,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 268,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 269,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rollbacks active transactions within the manager
     * Collect will remove the transaction from the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 252,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 251,
          'last-line' => 273,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollbackPendent',
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
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 276,
                  'char' => 14,
                ),
                'name' => 'rollback',
                'call-type' => 1,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 276,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 277,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Rollbacks active transactions within the manager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 275,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 274,
          'last-line' => 281,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDbService',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'service',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 282,
              'char' => 49,
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
                  'property' => 'service',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'service',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 284,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 284,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 286,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 286,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 287,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the database service used to run the isolated transactions
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 283,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 283,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 283,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 282,
          'last-line' => 291,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
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
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 292,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 292,
              'char' => 50,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 294,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 294,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 295,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injection container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 293,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 292,
          'last-line' => 300,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRollbackPendent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackPendent',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 301,
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
                  'property' => 'rollbackPendent',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'rollbackPendent',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 303,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 303,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 305,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 305,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 306,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set if the transaction manager must register a shutdown function to clean
     * up pendent transactions
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
                  'value' => 'ManagerInterface',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 302,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 302,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 302,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 301,
          'last-line' => 310,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'collectTransaction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'transaction',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'TransactionInterface',
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 311,
                'char' => 76,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 311,
              'char' => 77,
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
                  'variable' => 'managedTransaction',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 313,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 314,
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
                  'variable' => 'newTransactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 314,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 316,
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
                  'variable' => 'newTransactions',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 316,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 316,
                  'char' => 33,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 318,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 318,
                  'char' => 40,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'transactions',
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 318,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                'line' => 318,
                'char' => 54,
              ),
              'value' => 'managedTransaction',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'managedTransaction',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 319,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'transaction',
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 319,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 319,
                    'char' => 50,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'newTransactions',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'transaction',
                            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                            'line' => 320,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 320,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 321,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property-decr',
                          'variable' => 'this',
                          'property' => 'number',
                          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                          'line' => 322,
                          'char' => 35,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                      'line' => 323,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 324,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 326,
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
                  'property' => 'transactions',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'newTransactions',
                    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                    'line' => 326,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
                  'line' => 326,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
              'line' => 327,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes transactions from the TransactionManager
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
            'line' => 312,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
          'line' => 311,
          'last-line' => 328,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
      'line' => 68,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Transaction/Manager.zep',
    'line' => 68,
    'char' => 5,
  ),
);