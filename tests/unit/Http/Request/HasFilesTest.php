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

use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class HasFilesTest extends AbstractHttpBase
{
    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-01-31
     */
    public function testRequestHasFiles(): void
    {
        $request = $this->getRequestObject();

        $actual = $request->hasFiles();
        $this->assertFalse($actual);

        $_FILES = [
            'test' => [
                'name'     => 'name',
                'type'     => Http::CONTENT_TYPE_PLAIN,
                'size'     => 1,
                'tmp_name' => 'tmp_name',
                'error'    => 0,
            ],
        ];

        $actual = $request->hasFiles();
        $this->assertTrue($actual);
    }
}
