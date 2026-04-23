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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetReusableRecordsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     *
     * @group  sqlite
     * @group  mysql
     * @group  pgsql
     */
    public function testMvcModelManagerGetReusableRecords(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->get('modelsManager');

        $records = ['record1', 'record2'];
        $manager->setReusableRecords('SomeModel', 'key-xyz', $records);

        $actual = $manager->getReusableRecords('SomeModel', 'key-xyz');
        $this->assertSame($records, $actual);

        $actual = $manager->getReusableRecords('SomeModel', 'key-missing');
        $this->assertNull($actual);
    }
}
