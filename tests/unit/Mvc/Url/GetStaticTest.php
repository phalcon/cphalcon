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

namespace Phalcon\Tests\Unit\Mvc\Url;

use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetStaticTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcUrlGetStatic(): void
    {
        $url = new Url();

        $url->setStaticBaseUri('https://phalcon.io');

        $expected = 'https://phalcon.io/en/team';
        $actual   = $url->getStatic('/en/team');
        $this->assertEquals($expected, $actual);
    }
}
