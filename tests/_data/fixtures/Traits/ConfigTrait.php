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

namespace Phalcon\Test\Fixtures\Traits;

use Phalcon\Config;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use UnitTester;
use function dataFolder;

/**
 * Trait ConfigTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait ConfigTrait
{
    /**
     * @var array
     */
    protected $config = [
        'phalcon'     => [
            'baseuri' => '/phalcon/',
        ],
        'models'      => [
            'metadata' => 'memory',
        ],
        'database'    => [
            'adapter'  => 'mysql',
            'host'     => 'localhost',
            'username' => 'user',
            'password' => 'passwd',
            'name'     => 'demo',
        ],
        'test'        => [
            'parent' => [
                'property'  => 1,
                'property2' => 'yeah',
            ],
        ],
        'issue-12725' => [
            'channel' => [
                'handlers' => [
                    0 => [
                        'name'           => 'stream',
                        'level'          => 'debug',
                        'fingersCrossed' => 'info',
                        'filename'       => 'channel.log',
                    ],
                    1 => [
                        'name'           => 'redis',
                        'level'          => 'debug',
                        'fingersCrossed' => 'info',
                    ],
                ],
            ],
        ],
    ];

    /**
     * Tests Phalcon\Config\Adapter\* :: __construct()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkConstruct(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'construct'));
        $config = $this->getConfig($adapter);
        $this->compareConfig($I, $this->config, $config);
    }

    /**
     * Returns the message to print out for the test
     *
     * @param string $adapter
     *
     * @return string
     */
    private function getMessage(string $adapter = ''): string
    {
        $class = '';

        if ('' !== $adapter) {
            $class = sprintf('\Adapter\%s', $adapter);
        }

        return 'Config' . $class . ' - %s';
    }

    /**
     * Returns a config object
     *
     * @param string $adapter
     *
     * @return Config|Ini|Json|Php|Yaml
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function getConfig(string $adapter = '')
    {
        switch ($adapter) {
            case 'Ini':
                return new Ini(dataFolder('assets/config/config.ini'));
            case 'Json':
                return new Json(dataFolder('assets/config/config.json'));
            case 'Php':
                return new Php(dataFolder('assets/config/config.php'));
            case 'Yaml':
                return new Yaml(dataFolder('assets/config/config.yml'));
            default:
                return new Config($this->config);
        }
    }

    /**
     * @param UnitTester $I
     * @param array      $actual
     * @param Config     $expected
     */
    private function compareConfig(UnitTester $I, array $actual, Config $expected)
    {
        $I->assertEquals($actual, $expected->toArray());

        foreach ($actual as $key => $value) {
            $I->assertTrue(isset($expected->$key));

            if (is_array($value)) {
                $this->compareConfig($I, $value, $expected->$key);
            }
        }
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: count()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Faruk Brbovic <fbrbovic@devstub.com>
     * @since  2014-11-03
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkCount(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'count()'));
        $config = $this->getConfig($adapter);

        $expected = 5;
        $actual   = $config->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: get()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkGet(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'get()'));
        $config = $this->getConfig($adapter);

        $expected = 'memory';
        $actual   = $config->get('models')->get('metadata');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: getPathDelimiter()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkGetPathDelimiter(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'getPathDelimiter()'));
        $config = $this->getConfig($adapter);

        $existing = $config->getPathDelimiter();

        $expected = '.';
        $actual   = $config->getPathDelimiter();
        $I->assertEquals($expected, $actual);

        $config->setPathDelimiter('/');

        $expected = '/';
        $actual   = $config->getPathDelimiter();
        $I->assertEquals($expected, $actual);

        $config->setPathDelimiter($existing);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: offsetExists()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkOffsetExists(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'offsetExists()'));
        $config = $this->getConfig($adapter);

        $actual = $config->offsetExists('models');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: offsetGet()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkOffsetGet(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'offsetGet()'));
        $config = $this->getConfig($adapter);

        $expected = 'memory';
        $actual   = $config->offsetGet('models')->offsetGet('metadata');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: offsetSet()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkOffsetSet(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'offsetSet()'));
        $config = $this->getConfig($adapter);

        $config->offsetSet('models', 'something-else');

        $expected = 'something-else';
        $actual   = $config->offsetGet('models');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: offsetUnset()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkOffsetUnset(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'offsetUnset()'));
        $config = $this->getConfig($adapter);

        $actual = $config->offsetExists('database');
        $I->assertTrue($actual);

        $config->offsetUnset('database');
        $actual = $config->offsetGet('database');
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: path()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author michanismus
     * @since  2017-03-29
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkPath(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'path()'));
        $config = $this->getConfig($adapter);

        $expected = 'yeah';
        $actual   = $config->path('test.parent.property2');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: path() - default
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkPathDefault(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'path() - default'));
        $config = $this->getConfig($adapter);

        $expected = 'Unknown';
        $actual   = $config->path('test.parent.property3', 'Unknown');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: setPathDelimiter()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkSetPathDelimiter(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'setPathDelimiter()'));
        $config = $this->getConfig($adapter);

        $existing = $config->getPathDelimiter();

        $expected = 'yeah';
        $actual   = $config->path('test.parent.property2', 'Unknown');
        $I->assertEquals($expected, $actual);

        $config->setPathDelimiter('/');

        $expected = 'Unknown';
        $actual   = $config->path('test.parent.property2', 'Unknown');
        $I->assertEquals($expected, $actual);

        $expected = 'yeah';
        $actual   = $config->path('test/parent/property2', 'Unknown');
        $I->assertEquals($expected, $actual);

        $config->setPathDelimiter($existing);
    }

    /**
     * Tests Phalcon\Config\Adapter\* :: toArray()
     *
     * @param UnitTester $I
     * @param string     $adapter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    private function checkToArray(UnitTester $I, string $adapter = '')
    {
        $I->wantToTest(sprintf($this->getMessage($adapter), 'toArray()'));
        $config = $this->getConfig($adapter);

        $expected = $this->config;
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }
}
