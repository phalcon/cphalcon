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

use Phalcon\Mvc\Model;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class SetupTest extends AbstractDatabaseTestCase
{
    public function tearDown(): void
    {
        Settings::reset();
    }

    /**
     * setup() maps its options onto the global ORM settings.
     *
     * Tests Phalcon\Mvc\Model :: setup()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelSetup(): void
    {
        Model::setup(['notNullValidations' => false]);
        $this->assertFalse(Settings::get('orm.not_null_validations'));

        Model::setup(['notNullValidations' => true]);
        $this->assertTrue(Settings::get('orm.not_null_validations'));
    }
}
