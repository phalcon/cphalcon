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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Http\Response;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class ResponseTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-05
     */
    public function testHttpResponseInstanceOf(): void
    {
        $response = $this->getResponseObject();

        $this->assertInstanceOf(
            Response::class,
            $response
        );
    }
}
