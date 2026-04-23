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

final class GetSetBaseUriTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcUrlGetSetBaseUri(): void
    {
        $url = new Url();

        $path = 'https://phalcon.io';
        $url->setBaseUri($path);

        $expected = $path;
        $actual   = $url->getBaseUri();
        $this->assertEquals($expected, $actual);
    }
}
