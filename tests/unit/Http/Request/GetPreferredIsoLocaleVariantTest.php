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

final class GetPreferredIsoLocaleVariantTest extends AbstractHttpBase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                'es,es-ar;q=0.8',
                'es',
            ],
            [
                'es-ar;q=0.8',
                'es',
            ],
            [
                'en-US',
                'en',
            ],
            [
                'en',
                'en',
            ],
            [
                'some;random;string;here;q=1',
                'here',
            ],
            [
                '*',
                '',
            ],
            [
                '',
                '',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testHttpRequestGetBestLanguageIso(
        string $header,
        string $expected
    ) {
        $request = $this->container->get('request');

        $_SERVER['HTTP_ACCEPT_LANGUAGE'] = $header;

        $actual = $request->getPreferredIsoLocaleVariant();
        $this->assertSame($expected, $actual);
    }
}
