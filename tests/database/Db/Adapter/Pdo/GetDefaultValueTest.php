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

use function env;

final class GetDefaultValueTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getDefaultValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoGetDefaultValue(): void
    {
        $db    = $this->container->get('db');
        $value = $db->getDefaultValue();

        $this->assertInstanceOf(RawValue::class, $value);

        $expected = [
            'mysql'  => 'DEFAULT',
            'pgsql'  => 'DEFAULT',
            'sqlite' => 'NULL',
        ][env('driver')];

        $this->assertSame($expected, $value->getValue());
    }
}
