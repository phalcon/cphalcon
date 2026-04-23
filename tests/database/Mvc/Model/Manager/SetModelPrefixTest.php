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
use Phalcon\Tests\Support\Models\Robots;
use Phalcon\Tests\Support\Traits\DiTrait;

final class SetModelPrefixTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithoutPrefix(): void
    {
        $manager = new Manager();

        $robots = new Robots(null, null, $manager);

        $expected = 'robots';
        $actual   = $robots->getModelsManager()->getModelSource($robots);
        $this->assertEquals($expected, $actual);

        $actual = $robots->getSource();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/10328
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2017-04-15
     */
    public function testShouldReturnSourceWithPrefix(): void
    {
        $manager = new Manager();

        $manager->setModelPrefix('wp_');

        $robots = new Robots(null, null, $manager);

        $expected = 'wp_robots';
        $actual   = $robots->getModelsManager()->getModelSource($robots);
        $this->assertEquals($expected, $actual);

        $actual = $robots->getSource();
        $this->assertEquals($expected, $actual);
    }
}
