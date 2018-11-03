<?php

namespace  Phalcon\Test\Integration\Assets;

use IntegrationTester;
use Phalcon\Assets\Manager;

class ManagerCest
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/11409
     * @param IntegrationTester $I
     */
    public function addInlineJs(IntegrationTester $I)
    {
        $manager = new Manager();

        $js = file_get_contents(PATH_DATA . 'assets/signup.js');
        $manager->addInlineJs($js);
        $expected = "<script type=\"text/javascript\">{$js}</script>\n";

        ob_start();
        $manager->outputInlineJs();
        $actual = ob_get_contents();
        ob_end_clean();

        $I->assertSame($expected, $actual);
    }
}
