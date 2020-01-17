<?php
declare(strict_types=1);

/**
 * Class ExceptionController
 */

namespace Phalcon\Test\Controllers;

class ExceptionController extends \Phalcon\Mvc\Controller
{
    public function indexAction()
    {
        throw new \Exception('whups bad controller');
    }

    public function secondAction()
    {
        return 'I should be displayed';
    }
}
