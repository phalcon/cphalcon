<?php
declare(strict_types=1);

/**
 * Class ExceptionController
 */
class ExceptionController extends \Phalcon\Mvc\Controller\AbstractController
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
