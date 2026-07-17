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
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetAttributesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestGetAttributes(): void
    {
        $request = new Request();

        $attributes = $request->getAttributes();

        $this->assertInstanceOf(AttributeBag::class, $attributes);
        $this->assertSame([], $attributes->all());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestGetAttributesMutationsPersist(): void
    {
        $request = new Request();

        $request->getAttributes()->set('user', 'nikos');

        $this->assertTrue($request->getAttributes()->has('user'));
        $this->assertSame('nikos', $request->getAttributes()->get('user'));

        $request->getAttributes()->remove('user');

        $this->assertFalse($request->getAttributes()->has('user'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testHttpRequestGetAttributesReturnsSameInstance(): void
    {
        $request = new Request();

        $this->assertSame(
            $request->getAttributes(),
            $request->getAttributes()
        );
    }
}
