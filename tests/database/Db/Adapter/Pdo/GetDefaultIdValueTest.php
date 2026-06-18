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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function env;

final class GetDefaultIdValueTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getDefaultIdValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoGetDefaultIdValue(): void
    {
        $db    = $this->container->get('db');
        $value = $db->getDefaultIdValue();

        $this->assertInstanceOf(RawValue::class, $value);

        $expected = [
            'mysql'  => 'null',
            'pgsql'  => 'DEFAULT',
            'sqlite' => 'null',
        ][env('driver')];

        $this->assertSame($expected, $value->getValue());
    }
}
