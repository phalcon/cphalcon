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

namespace Phalcon\Test\Unit\Queue\Beanstalk;

use UnitTester;

/**
 * Class ReadYamlCest
 */
class ReadYamlCest
{
    /**
     * Tests Phalcon\Queue\Beanstalk :: readYaml()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function queueBeanstalkReadYaml(UnitTester $I)
    {
        $I->wantToTest('Queue\Beanstalk - readYaml()');
        $I->skipTest('Need implementation');
    }
}
