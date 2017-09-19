<?php

namespace Phalcon\Test\Unit\Mvc\Model\Resultset;

use Phalcon\Di;
use Phalcon\Test\Models\Robots;
use Helper\ResultsetHelperTrait;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Mvc\Model\Resultset\Complex;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Resultset\ComplexTest
 * Tests the Phalcon\Mvc\Model\Resultset\Complex component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Resultset
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ComplexTest extends UnitTest
{
    use ResultsetHelperTrait;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->setUpEnvironment();
    }

    /**
     * Work with Complex Resultset by load data from the file cache (PHQL option).
     *
     * @test
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-12-28
     */
    public function shouldLoadResultsetFromCacheByUsingPhql()
    {
        $this->specify(
            'Complex Resultset does not work as expected (PHQL option)',
            function () {
                $cache = $this->getFileCache();
                $this->setUpModelsCache($cache);

                $modelsManager = Di::getDefault()->get('modelsManager');

                $robots = $modelsManager->executeQuery(
                    'SELECT r.*, p.* FROM ' . Robots::class . ' r JOIN ' . RobotsParts::class . ' p '
                );

                expect($robots)->isInstanceOf(Complex::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $cache->save('test-resultset', $robots);

                $this->tester->amInPath(PATH_CACHE);
                $this->tester->seeFileFound('test-resultset');

                $robots = $cache->get('test-resultset');

                expect($robots)->isInstanceOf(Complex::class);
                expect($robots)->count(3);
                expect($robots->count())->equals(3);

                $this->tester->deleteFile('test-resultset');
            }
        );
    }
}
