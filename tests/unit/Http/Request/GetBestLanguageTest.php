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

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class GetBestLanguageTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetBestLanguage(): void
    {
        $request = $this->getRequestObject();

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = 'es,es-ar;q=0.8,en;q=0.5,en-us;q=0.3,de-de; q=0.9';

        $accept = $request->getLanguages();
        $this->assertCount(5, $accept);


        $firstAccept = $accept[0];

        $expected = 'es';
        $actual   = $firstAccept['language'];
        $this->assertSame($expected, $actual);

        $expected = 1.0;
        $actual   = $firstAccept['quality'];
        $this->assertSame($expected, $actual);

        $fourthAccept = $accept[3];

        $expected = 'en-us';
        $actual   = $fourthAccept['language'];
        $this->assertSame($expected, $actual);

        $expected = 0.3;
        $actual   = $fourthAccept['quality'];
        $this->assertSame($expected, $actual);

        $lastAccept = $accept[4];

        $expected = 'de-de';
        $actual   = $lastAccept['language'];
        $this->assertSame($expected, $actual);

        $expected = 0.9;
        $actual   = $lastAccept['quality'];
        $this->assertSame($expected, $actual);

        $expected = 'es';
        $actual   = $request->getBestLanguage();
        $this->assertSame($expected, $actual);
    }
}
