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

final class GetStaticBaseUriTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function testMvcUrlGetStaticBaseUri(): void
    {
        $url = new Url();
        $url->setStaticBaseUri('/static/');
        $this->assertSame('/static/', $url->getStaticBaseUri());
    }
}
