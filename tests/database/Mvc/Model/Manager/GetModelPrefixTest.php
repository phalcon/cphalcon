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

final class GetModelPrefixTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-04
     */
    public function testMvcModelManagerGetModelPrefix(): void
    {
        $manager = new Manager();

        $expected = '';
        $actual   = $manager->getModelPrefix();
        $this->assertEquals($expected, $actual);

        $manager->setModelPrefix('wp_');

        $expected = 'wp_';
        $actual   = $manager->getModelPrefix();
        $this->assertEquals($expected, $actual);
    }
}
