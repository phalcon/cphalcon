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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetHttpMethodParameterOverrideTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetSetHttpMethodParameterOverride(): void
    {
        $request = new Request();

        $actual = $request->getHttpMethodParameterOverride();
        $this->assertFalse($actual);

        $request->setHttpMethodParameterOverride(true);

        $actual = $request->getHttpMethodParameterOverride();
        $this->assertTrue($actual);
    }
}
