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

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @return array
     */
    public static function getExamples(): array
    {
        return [
            [
                'https://phalcon.io',
                null,
            ],
            [
                'https://phalcon.io',
                '',
            ],
            [
                'https://phalcon.io/',
                '/',
            ],
            [
                'https://phalcon.io/en/team',
                '/en/team',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testMvcUrlGet(
        string $expected,
        ?string $name
    ): void {
        $url = new Url();

        $url->setBaseUri('https://phalcon.io');

        $actual = $url->get($name);
        $this->assertEquals($expected, $actual);
    }
}
