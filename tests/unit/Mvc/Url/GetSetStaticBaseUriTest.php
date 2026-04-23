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

final class GetSetStaticBaseUriTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcUrlGetSetStaticBaseUri(): void
    {
        $url = new Url();

        $path = 'https://phalcon.io';

        $url->setStaticBaseUri($path);

        $this->assertEquals(
            $path,
            $url->getStaticBaseUri()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcUrlGetSetStaticBaseUriGetBaseUri(): void
    {
        $url = new Url();

        $expected = 'https://phalcon.io';

        $url->setBaseUri($expected);

        $actual = $url->getStaticBaseUri();

        $this->assertEquals($expected, $actual);
    }
}
