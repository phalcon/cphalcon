<?php

namespace Phalcon\Test\Unit\Assets;

use Phalcon\Assets\Inline;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Assets\InlineTest
 * Tests the \Phalcon\Assets\Inline component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Asset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class InlineTest extends UnitTest
{
    /**
     * Tests getType
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-06-02
     */
    public function getResourceKey()
    {
        $this->specify(
            "Unable to get inline resource key or resorce key is incorrect",
            function () {
                $resource = new Inline('js', '<script>alert("Hello");</script>');

                expect(md5('js:<script>alert("Hello");</script>'))->equals($resource->getResourceKey());
            }
        );
    }
}
