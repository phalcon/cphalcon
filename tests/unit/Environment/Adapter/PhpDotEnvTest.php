<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test;


use Codeception\Test\Unit;
use DotEnv\DotEnv;
use Phalcon\Di;
use Phalcon\Environment\Adapter\PhpDotEnv;
use UnitTester;

class EnvironmentTest extends Unit
{
    /** @var Environment  */
    private $testSubject = null;

    /** @var UnitTester */
    protected $tester;

    public function _before()
    {
        $this->testSubject = new PhpDotEnv();

        $di = new Di();

        $mockLoader = $this->getMockBuilder(DotEnv::class)
                           ->disableOriginalConstructor()
                           ->setMethods(['getEnvironmentVariable'])
                           ->getMock();

        $di->set(DotEnv::class, $mockLoader);

        $this->testSubject->setDi($di);
    }

    public function _after()
    {
        putenv('SOME_RANDOM_VALUE');
    }


    public function testFallback()
    {
        putenv('SOME_RANDOM_VALUE=blah');

        $this->assertEquals('blah', $this->testSubject->getValue('SOME_RANDOM_VALUE'));
    }

    public function testLoader()
    {
        $this->testSubject->getDi()->get(DotEnv::class)->expects($this->once())->method('getEnvironmentVariable')->with('SOME_RANDOM_VALUE')->willReturn('blah');
        $this->assertEquals('blah', $this->testSubject->getValue('SOME_RANDOM_VALUE'));
    }
}
