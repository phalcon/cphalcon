<?php
/**
 * AssetsMultipleTest.php
 * \Phalcon\Resource\AssetsMultipleTest
 *
 * Tests the Phalcon\Assets\Multiple component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Assets;

use \Phalcon\DI as PhDI;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class AssetsMultipleTest extends TBase
{
    public function testFilterMultiplesSourcesNoFilter()
    {
        $this->markTestIncomplete('To be checked');
        @unlink('unit-tests/assets/production/combined-1.js');
        
        Phalcon\DI::reset();
        
        $di = new Phalcon\DI();
        
        $di['url'] = function () {
            $url = new Phalcon\Mvc\Url();
            $url->setStaticBaseUri('/');
            return $url;
        };
        
        $di->set(
            'escaper',
            function () {
                return new \Phalcon\Escaper();
            }
        );
        
        $assets = new PhTAssetsManager();
        
        $assets->useImplicitOutput(false);
        
        $js = $assets->collection('js');
        
        $js->setTargetPath('unit-tests/assets/production/combined-1.js');
        
        $js->setTargetUri('production/combined.js');
        
        $js->addJs('jquery.js', false, false);
        $js->addJs('gs.js');
        
        //Basic output
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL
        );
        
        //Enabling join
        $js->join(true);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' .
            PHP_EOL
        );
        
        //Disabling join
        $js->join(false);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL
        );
    }

    public function testFilterMultiplesSourcesFilterNoJoin()
    {
        $this->markTestIncomplete('To be checked');
        @unlink('unit-tests/assets/production/combined-2.js');
        
        Phalcon\DI::reset();
        
        $di = new Phalcon\DI();
        
        $di['url'] = function () {
            $url = new Phalcon\Mvc\Url();
            $url->setStaticBaseUri('/');
            return $url;
        };
        
        $di->set(
            'escaper',
            function () {
                return new \Phalcon\Escaper();
            }
        );
        
        $assets = new PhTAssetsManager();
        
        $assets->useImplicitOutput(false);
        
        $js = $assets->collection('js');
        
        $js->setTargetPath('unit-tests/assets/production/');
        
        $jquery = new PhTAssetsResourceJs('unit-tests/assets/jquery.js', false, false);
        
        $jquery->setTargetUri('jquery.js');
        
        $js->add($jquery);
        
        $gs = new PhTAssetsResourceJs('unit-tests/assets/gs.js');
        
        $gs->setTargetUri('gs.js');
        $gs->setTargetPath('gs.js');
        
        $js->add($gs);
        
        //Basic output
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL . '<script type="text/javascript" src="/gs.js"></script>' .
            PHP_EOL
        );

        //Enabling join
        $js->join(true);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL
        );

        //Disabling join
        $js->join(false);
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' . PHP_EOL
        );

        $js->addFilter(new Phalcon\Assets\Filters\None());
        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="/jquery.js"></script>' .
            PHP_EOL .
            '<script type="text/javascript" src="/gs.js"></script>' .
            PHP_EOL
        );
    }

    public function testFilterMultiplesSourcesFilterJoin()
    {
        $this->markTestIncomplete('To be checked');
        @unlink('unit-tests/assets/production/combined-3.js');
        
        Phalcon\DI::reset();
        
        $di = new Phalcon\DI();
        
        $di['url'] = function () {
            $url = new Phalcon\Mvc\Url();
            $url->setStaticBaseUri('/');
            return $url;
        };
        
        $di->set(
            'escaper',
            function () {
                return new \Phalcon\Escaper();
            }
        );

        $assets = new PhTAssetsManager();
        
        $assets->useImplicitOutput(false);
        
        $js = $assets->collection('js');
        
        $js->setTargetUri('production/combined-3.js');
        $js->setTargetPath('unit-tests/assets/production/combined-3.js');
        
        $jquery = new PhTAssetsResourceJs('unit-tests/assets/jquery.js', false, false);
        
        $jquery->setTargetUri('jquery.js');
        
        $js->add($jquery);
        
        $gs = new PhTAssetsResourceJs('unit-tests/assets/gs.js');
        
        $gs->setTargetUri('gs.js');
        $gs->setTargetPath('gs.js');
        
        $js->add($gs);
        $js->join(true);
        
        //Use two filters
        $js->addFilter(new Phalcon\Assets\Filters\None());
        $js->addFilter(new Phalcon\Assets\Filters\None());

        $this->assertEquals(
            $assets->outputJs('js'),
            '<script type="text/javascript" src="/production/combined-3.js"></script>' .
            PHP_EOL
        );
    }
}
