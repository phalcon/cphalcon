<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use Phalcon\Config;
use Phalcon\Config\Adapter\Grouped;
use Phalcon\Config\Exception;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

use function dataDir;

class ConstructCest
{
    use ConfigTrait;

    public function _after()
    {
        unset($this->config['test']['property']); //Removing Extra Property
    }

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __construct() - complex instance
     *
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function configAdapterGroupedConstructComplexInstance(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - construct - complex instance");

        $this->config['test']['property2'] = 'something-else';
        $this->config['test']['property']  = 'blah';

        $config = [
            dataDir('assets/config/config.php'),
            [
                'adapter'  => 'json',
                'filePath' => dataDir('assets/config/config.json'),
            ],
            [
                'adapter' => 'array',
                'config'  => [
                    'test' => [
                        'property2' => 'something-else',
                    ],
                ],
            ],
            new Config([
                'test' => [
                    'property' => 'blah',
                ],
            ]),
        ];

        foreach ([[], ['']] as $parameters) {
            $this->compareConfig(
                $I,
                $this->config,
                new Grouped($config, ...$parameters)
            );
        }
    }

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __construct() - default adapter
     *
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function configAdapterGroupedConstructDefaultAdapter(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - construct - default adapter");

        $this->config['test']['property2'] = 'something-else';

        $config = [
            [
                'filePath' => dataDir('assets/config/config.json'),
            ],
            [
                'adapter' => 'array',
                'config'  => [
                    'test' => [
                        'property2' => 'something-else',
                    ],
                ],
            ],
        ];

        $object = new Grouped($config, 'json');

        $this->compareConfig(
            $I,
            $this->config,
            $object
        );
    }

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __construct() - exception
     *
     * @author Fenikkusu
     * @since  2017-06-06
     */
    public function configAdapterGroupedConstructThrowsException(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - construct array without config throws exception");

        $I->expectThrowable(
            new Exception(
                "To use 'array' adapter you have to specify the 'config' as an array."
            ),
            function () {
                new Grouped(
                    [
                        [
                            'adapter' => 'array',
                        ],
                    ]
                );
            }
        );
    }
}
