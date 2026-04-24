<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function spl_object_hash;

final class CreateBuilderTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-07-04
     *
     * @group mysql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelManagerCreateBuilder(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        /** @var ManagerInterface $manager */
        $manager = $this->getService("modelsManager");
        $actual = $manager->getBuilder();
        $this->assertNull($actual);
        $builder    = $manager->createBuilder();
        $getBuilder = $manager->getBuilder();
        $expected   = spl_object_hash($builder);
        $actual     = spl_object_hash($getBuilder);
        $this->assertSame($expected, $actual);
        $builder  = $manager->createBuilder();
        $expected = spl_object_hash($builder);
        $this->assertNotSame($expected, $actual);
    }
}
