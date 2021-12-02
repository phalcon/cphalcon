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

namespace Phalcon\Tests\Integration\Mvc\Url;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Url;

class GetCest
{
    /**
     * Tests Phalcon\Mvc\Url :: get()
     *
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGet(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Url - get() - ' . $example[0]);

        $url = new Url();

        $url->setBaseUri('https://phalcon.io');

        $expected = $example[1];
        $actual   = $url->get($example[2]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'null',
                'https://phalcon.io',
                null,
            ],
            [
                'empty',
                'https://phalcon.io',
                '',
            ],
            [
                '/',
                'https://phalcon.io/',
                '/',
            ],
            [
                'url',
                'https://phalcon.io/en/team',
                '/en/team',
            ],
        ];
    }
}
