<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use Phalcon\Config\Adapter\Grouped;
use Phalcon\Factory\Exception;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;
use function dataFolder;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __construct() - complex instance
     *
     * @param UnitTester $I
     *
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function configAdapterGroupedConstructComplexInstance(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - construct - complex");
        $this->config["test"]["property2"] = "something-else";

        $config = [
            dataFolder('assets/config/config.php'),
            [
                'filePath' => dataFolder('assets/config/config.json'),
                'adapter'  => 'json',
            ],
            [
                'adapter' => 'array',
                'config'  => [
                    "test" => [
                        "property2" => "something-else",
                    ],
                ],
            ],
        ];

        foreach ([[], ['']] as $parameters) {
            $this->compareConfig($I, $this->config, new Grouped($config, ...$parameters));
        }
    }

    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __construct() - exception
     *
     * @param UnitTester $I
     *
     * @author Fenikkusu
     * @since  2017-06-06
     */
    public function configAdapterGroupedConstructThrowsException(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Grouped - construct array without config throws exception");
        $I->expectThrowable(
            new Exception("To use 'array' adapter you have to specify the 'config' as an array."),
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
