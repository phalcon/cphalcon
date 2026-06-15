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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\PersonasMigration;
use Phalcon\Tests\Support\Models\Personas;
use Phalcon\Tests\Support\Traits\DiTrait;

final class SaveNullDefaultTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $connection = self::getConnection();
        new PersonasMigration($connection);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * A nullable column declared `DEFAULT NULL` must remain `null` on the model
     * attribute after save(). On MySQL, `INFORMATION_SCHEMA.COLUMNS` reports
     * such a column's default as the literal string "NULL"; previously that
     * string was written back onto the attribute, turning a null value into the
     * string "NULL" after save.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17176
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-15
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelSaveKeepsNullForDefaultNullColumn(): void
    {
        $persona                    = new Personas();
        $persona->cedula            = 'C-17176';
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'Null Default';
        $persona->telefono          = null;
        $persona->cupo              = 0;
        $persona->estado            = 'A';

        $result = $persona->save();

        $this->assertTrue($result);

        // The nullable `telefono` column must stay null, not become "NULL".
        $this->assertNull($persona->telefono);

        // The persisted value must also be null when read back.
        $stored = Personas::findFirst(
            [
                'conditions' => 'cedula = :cedula:',
                'bind'       => ['cedula' => 'C-17176'],
            ]
        );

        $this->assertNotNull($stored);
        $this->assertNull($stored->telefono);
    }
}
