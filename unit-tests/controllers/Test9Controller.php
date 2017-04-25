<?php

class Test9Controller extends Phalcon\Mvc\Controller
{

    public function indexAction()
    {
        global $noCallAction_value;
        $noCallAction_value = 14;
    }

    /**
     * noCallAction
     */
    public function noCallAction()
    {
        global $noCallAction_value;
        $noCallAction_value = 533;
    }

}
