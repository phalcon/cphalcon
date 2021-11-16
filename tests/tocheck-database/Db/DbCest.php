<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Db;

use Codeception\Example;
use IntegrationTester;
use PDO;
use Phalcon\Db\Enum;
use Phalcon\Db\RawValue;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class DbCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Db
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider adaptersProvider
     */
    public function db(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db - ' . $example[0]);

        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $connection = $this->getService('db');

        $I->assertTrue(
            $connection->execute('DELETE FROM prueba')
        );

        $I->assertTrue(
            $connection->execute(
                'INSERT INTO prueba(id, nombre, estado) VALUES (' . $connection->getDefaultIdValue() . ', ?, ?)',
                [
                    'LOL 1',
                    'A',
                ]
            )
        );

        $I->assertTrue(
            $connection->execute(
                'UPDATE prueba SET nombre = ?, estado = ?',
                [
                    'LOL 11',
                    'R',
                ]
            )
        );

        $I->assertTrue(
            $connection->execute(
                'DELETE FROM prueba WHERE estado = ?',
                [
                    'R',
                ]
            )
        );

        $I->assertTrue(
            $connection->insert(
                'prueba',
                [
                    $connection->getDefaultIdValue(),
                    'LOL 1',
                    'A',
                ]
            )
        );

        $I->assertTrue(
            $connection->insert(
                'prueba',
                [
                    'LOL 2',
                    'E',
                ],
                [
                    'nombre',
                    'estado',
                ]
            )
        );

        $I->assertTrue(
            $connection->insert(
                'prueba',
                [
                    'LOL 3',
                    'I',
                ],
                [
                    'nombre',
                    'estado',
                ]
            )
        );

        $I->assertTrue(
            $connection->insert(
                'prueba',
                [
                    new RawValue('current_date'),
                    'A',
                ],
                [
                    'nombre',
                    'estado',
                ]
            )
        );

        for ($i = 0; $i < 50; $i++) {
            $I->assertTrue(
                $connection->insert(
                    'prueba',
                    [
                        'LOL ' . $i,
                        'F',
                    ],
                    [
                        'nombre',
                        'estado',
                    ]
                )
            );
        }

        $I->assertTrue(
            $connection->update(
                'prueba',
                [
                    'nombre',
                    'estado',
                ],
                [
                    'LOL 1000',
                    'X',
                ],
                "estado='E'"
            )
        );

        $I->assertTrue(
            $connection->update(
                'prueba',
                [
                    'nombre',
                ],
                [
                    'LOL 3000',
                ],
                "estado='X'"
            )
        );

        $I->assertTrue(
            $connection->update(
                'prueba',
                [
                    'nombre',
                ],
                [
                    new RawValue('current_date'),
                ],
                "estado='X'"
            )
        );

        // Test array syntax for $whereCondition
        $I->assertTrue(
            $connection->insert(
                'prueba',
                [
                    'LOL array syntax',
                    'E',
                ],
                [
                    'nombre',
                    'estado',
                ]
            )
        );

        $success = $connection->update(
            'prueba',
            ['nombre', 'estado'],
            ['LOL array syntax 2', 'X'],
            [
                'conditions' => 'nombre=? and estado = ?',
                'bind'       => ['LOL array syntax', 'E'],
                'bindTypes'  => [PDO::PARAM_STR, PDO::PARAM_STR],
            ],
            [PDO::PARAM_STR, PDO::PARAM_STR]
        );
        $I->assertTrue($success);

        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Enum::FETCH_ASSOC,
            [
                'LOL array syntax 2', 'X',
            ]
        );
        $I->assertEquals(1, $row['cnt']);

        $success = $connection->update(
            'prueba',
            [
                'nombre',
                'estado',
            ],
            [
                'LOL array syntax 3',
                'E',
            ],
            [
                'conditions' => 'nombre=? and estado = ?',
                'bind'       => [
                    'LOL array syntax 2',
                    'X',
                ],
            ]
        );
        $I->assertTrue($success);

        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Enum::FETCH_ASSOC,
            [
                'LOL array syntax 3', 'E',
            ]
        );
        $I->assertEquals(1, $row['cnt']);

        //test insertAsDict and updateAsDict
        $success = $connection->insertAsDict(
            'prueba',
            [
                'nombre' => 'LOL insertAsDict',
                'estado' => 'E',
            ]
        );

        $I->assertTrue($success);

        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Enum::FETCH_ASSOC,
            [
                'LOL insertAsDict', 'E',
            ]
        );
        $I->assertEquals(1, $row['cnt']);

        $I->assertTrue(
            $connection->updateAsDict(
                'prueba',
                [
                    'nombre' => 'LOL updateAsDict',
                    'estado' => 'X',
                ],
                "nombre='LOL insertAsDict' and estado = 'E'"
            )
        );

        $row = $connection->fetchOne(
            'select count(*) as cnt from prueba where nombre=? and estado=?',
            Enum::FETCH_ASSOC,
            [
                'LOL updateAsDict', 'X',
            ]
        );
        $I->assertEquals(1, $row['cnt']);

        $I->assertTrue(
            $connection->delete('prueba', "estado='X'")
        );

        $I->assertTrue(
            $connection->delete('prueba')
        );

        $I->assertEquals(
            54,
            $connection->affectedRows()
        );

        $I->assertCount(
            11,
            $connection->fetchOne('SELECT * FROM personas')
        );

        $I->assertCount(
            11,
            $connection->fetchOne('SELECT * FROM personas', Enum::FETCH_NUM)
        );

        $I->assertCount(
            10,
            $connection->fetchAll('SELECT * FROM personas LIMIT 10')
        );

        $rows = $connection->fetchAll(
            'SELECT * FROM personas LIMIT 10',
            Enum::FETCH_NUM
        );
        $I->assertCount(10, $rows);
        $I->assertCount(11, $rows[0]);

        $I->assertEquals(
            3,
            $connection->fetchColumn('SELECT id FROM robots ORDER BY year DESC')
        );

        $I->assertEquals(
            'mechanical',
            $connection->fetchColumn('SELECT * FROM robots where id=?', [1], 2)
        );

        $I->assertEquals(
            'mechanical',
            $connection->fetchColumn(
                'SELECT * FROM robots where id=?',
                [1],
                'type'
            )
        );

        //Auto-Increment/Serial Columns
        $sql = 'INSERT INTO subscriptores(id, email, created_at, status) '
            . 'VALUES (' . $connection->getDefaultIdValue() . ', ?, ?, ?)';
        $I->assertTrue(
            $connection->execute(
                $sql,
                [
                    'shirley@garbage.com',
                    '2011-01-01 12:59:13',
                    'P',
                ]
            )
        );

        //Check for auto-increment column
        $I->assertGreaterThan(
            0,
            $connection->lastInsertId('subscriptores_id_seq')
        );


        // Create View
        $I->assertTrue(
            $connection->createView(
                'phalcon_test_view',
                [
                    'sql' => 'SELECT 1 AS one, 2 AS two, 3 AS three',
                ]
            )
        );

        // Check view exists
        $I->assertTrue(
            $connection->viewExists('phalcon_test_view')
        );

        // Gets the list of all views.
        $views = $connection->listViews();
        $I->assertTrue(is_array($views));
        $I->assertContains('phalcon_test_view', $views);

        // Execute created view
        $row = $connection->fetchOne('SELECT * FROM phalcon_test_view');
        $I->assertCount(3, $row);
        $I->assertArrayHasKey('one', $row);
        $I->assertEquals(2, $row['two']);

        // Drop view
        $I->assertTrue(
            $connection->dropView('phalcon_test_view')
        );


        //Transactions without savepoints.
        $connection->setNestedTransactionsWithSavepoints(false);

        // level 1 - real
        $I->assertTrue(
            $connection->begin()
        );

        // level 2 - virtual
        $I->assertFalse(
            $connection->begin()
        );

        // level 3 - virtual
        $I->assertFalse(
            $connection->begin()
        );

        // level 2 - virtual
        $I->assertFalse(
            $connection->rollback()
        );

        // level 1 - virtual
        $I->assertFalse(
            $connection->commit()
        );

        // commit - real
        $I->assertTrue(
            $connection->commit()
        );

        // level 1 - real
        $I->assertTrue(
            $connection->begin()
        );

        // level 2 - virtual
        $I->assertFalse(
            $connection->begin()
        );

        // level 1 - virtual
        $I->assertFalse(
            $connection->commit()
        );

        // rollback - real
        $I->assertTrue(
            $connection->rollback()
        );

        // Transactions with savepoints.
        $connection->setNestedTransactionsWithSavepoints(true);

        // level 1 - begin transaction
        $I->assertTrue(
            $connection->begin()
        );

        // level 2 - uses savepoint_1
        $I->assertTrue(
            $connection->begin()
        );

        // level 3 - uses savepoint_2
        $I->assertTrue(
            $connection->begin()
        );

        // level 2 - uses rollback savepoint_2
        $I->assertTrue(
            $connection->rollback()
        );

        // level 1  - uses release savepoint_1
        $I->assertTrue(
            $connection->commit()
        );

        // commit - real commit
        $I->assertTrue(
            $connection->commit()
        );

        // level 1 - real begin transaction
        $I->assertTrue(
            $connection->begin()
        );

        // level 2 - uses savepoint_1
        $I->assertTrue(
            $connection->begin()
        );

        // level 1 - uses release savepoint_1
        $I->assertTrue(
            $connection->commit()
        );

        // rollback - real rollback
        $I->assertTrue(
            $connection->rollback()
        );
    }

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
